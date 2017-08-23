#ifndef ALORA_FABRICK_CLIENT_H

#include <Arduino.h>
#include <FabrickNetIF.h>
#include <FabrickUtil.h>

class AloraFabrickClient {
public:
    AloraFabrickClient();
    ~AloraFabrickClient();

    void begin(FabrickNetIF* netIface, String deviceId);
    bool sendTemperature(float temperatureInC);
    bool sendHumidity(float humidity);
    bool sendPressure(float pressure);
    bool sendLux(float luminance);
    bool sendAccelerometer(float x, float y, float z);
private:
    FabrickNetIF* fabrickIface;
    String id;
};

#endif