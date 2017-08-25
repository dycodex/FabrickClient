#ifndef FABRICK_NETWORK_INTERFACE_H
#define FABRICK_NETWORK_INTERFACE_H

/**
 * The abstract class of network interface (LoRa & WiFi) of the Fabrick client.
 * The LoRa one is compatible with the Atilze LoRa Shield.
 * @see FabrickLoRa
 */
class FabrickNetIF {
public:
    virtual ~FabrickNetIF() {};
    /**
     * The pure virtual function that will be implemented in LoRa and WiFi classes
     * @param deviceId Device ID that is registered on Fabrick cloud.
     * @param frameCounter counter of the frame inside a single payload. One frame can contain a fixed length of sensor payload.
     * @param channel channel number of the data.
     * @param dataType type of the data that wil be sent.
     * @param data the actual data that will be send to the Fabrick cloud.
     * @param dataeLengthInHex length of the data in the previous argument.
     * @return Indicate the result of the data transmission process.
     */
    virtual bool send(String deviceId, int frameCounter, int channel, int dataType, String data, int dataLengthInHex) = 0;
};

#endif
