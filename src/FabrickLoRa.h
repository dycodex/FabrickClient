#ifndef FABRICK_LORA_H
#define FABRICK_LORA_H

#include <Arduino.h>
#include <Stream.h>
#include "FabrickNetIF.h"
#include "FabrickUtil.h"

/** \example LoRaSendData/LoRaSendData.ino
 * Blueprint of the LoRa network interface for sending data to Fabrick
 */
class FabrickLoRa: public FabrickNetIF {
public:
    FabrickLoRa();
    ~FabrickLoRa();

    bool begin(Stream* stream);
    bool send(String deviceId, int frameCounter, int channel, int dataType, String data, int dataLengthInHex, bool waitOk = false);
    String getResponse();
private:
    Stream* loraStream;
};

#endif