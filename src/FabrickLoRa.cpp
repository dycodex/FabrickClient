#include "FabrickLoRa.h"

FabrickLoRa::FabrickLoRa() {
}

FabrickLoRa::~FabrickLoRa() {
}

/**
 * Initialize LoRa shield by checking AT command communication
 * @param stream any object of class that is derived from Stream class.
 * @return indicate whether we are able to communicate with the LoRa shield or not.
 */
bool FabrickLoRa::begin(Stream* stream) {
    loraStream = stream;
    int retryCount = 0;
    int maxRetry = 3;

    while (retryCount < maxRetry) {
        loraStream->print("AT\r\n");
        String response = getResponse();

        if (response.indexOf("OK") > -1) {
            return true;
        } else {
            retryCount++;
            delay(100);
        }
    }

    return false;
}

/**
 * Get response from AT command
 * @return response from previous AT command
 */
String FabrickLoRa::getResponse() {
    String result = "";
    while (loraStream->available()) {
        result += String((char)loraStream->read());
    }

    return result;
}


/**
 * Send data through LoRa shield.
 * @param deviceId Device ID that is registered on Fabrick cloud.
 * @param frameCounter counter of the frame inside a single payload. One frame can contain a fixed length of sensor payload.
 * @param channel channel number of the data.
 * @param dataType type of the data that wil be sent.
 * @param data the actual data that will be send to the Fabrick cloud.
 * @param dataeLengthInHex length of the data in the previous argument.
 * @return Indicate the result of the data transmission process.
 */
bool FabrickLoRa::send(String deviceId, int frameCounter, int channel, int dataType, String data, int dataLengthInHex) {
    // Please refer to IPSO Smart Object Document for packet format

    // Frame counter in hex string
    String frameCounterStr = FabrickUtils::addZeros(String(frameCounter, HEX), 2);

    // Channel number in hex string
    String dataChannelStr = FabrickUtils::addZeros(String(channel, HEX), 2);

    // Convert to HEX string for data type
    String dataTypeStr = FabrickUtils::addZeros(String(dataType - 3200, HEX), 2);

    // Pad payload with zeros
    String dataStr = FabrickUtils::addZeros(data, dataLengthInHex);

    // TX packet
    String txPacket = deviceId + frameCounterStr + dataChannelStr + dataTypeStr + dataStr;

    String txPacketLength = String(txPacket.length());
    String ATCommand = "AT+DTX=" + txPacketLength + "," + txPacket + "\r\n";

    loraStream->print(ATCommand.c_str());

    String response = getResponse();

    return response.indexOf("OK") > -1;
}
