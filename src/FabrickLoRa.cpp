#include "FabrickLoRa.h"

FabrickLoRa::FabrickLoRa() {
}

FabrickLoRa::~FabrickLoRa() {
}

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

String FabrickLoRa::getResponse() {
    String result = "";
    while (loraStream->available()) {
        result += String((char)loraStream->read());
    }

    return result;
}

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
