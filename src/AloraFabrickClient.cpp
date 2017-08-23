#include "AloraFabrickClient.h"

AloraFabrickClient::AloraFabrickClient() {
}

AloraFabrickClient::~AloraFabrickClient() {
}

void AloraFabrickClient::begin(FabrickNetIF* netIface, String deviceId) {
    fabrickIface = netIface;
    id = deviceId;
}

bool AloraFabrickClient::sendTemperature(float temperatureInC) {
    int tempInt = (int)(temperatureInC * 10);
    long tempLong = (tempInt >= 0) ? tempInt : (tempInt + 65536);
    int dataLength = 4; // 2 bytes
    String data = FabrickUtils::addZeros(String(tempLong, HEX), dataLength);

    int frameCnt = 1;
    int channel = 0;
    int type = 3303;

    return fabrickIface->send(id, frameCnt, channel, type, data, dataLength);
}

bool AloraFabrickClient::sendHumidity(float humidity) {
    int humInt = (int)(humidity * 50);
    int dataLength = 2; // 1 byte
    String data = FabrickUtils::addZeros(String(humInt, HEX), dataLength);

    int frameCnt = 1;
    int channel = 0;
    int type = 3304;

    return fabrickIface->send(id, frameCnt, channel, type, data, dataLength);
}

bool AloraFabrickClient::sendPressure(float pressure) {
    int pressInt = (int)pressure;
    int dataLength = 4; // 2 bytes
    String data = FabrickUtils::addZeros(String(pressInt, HEX), dataLength);

    int frameCnt = 1;
    int channel = 0;
    int type = 3315;

    return fabrickIface->send(id, frameCnt, channel, type, data, dataLength);
}

bool AloraFabrickClient::sendLux(float luminance) {
    int luminanceInt = (int)luminance;
    int dataLength = 6; // 3 bytes
    String data = FabrickUtils::addZeros(String(luminanceInt, HEX), dataLength);

    int frameCnt = 1;
    int channel = 0;
    int type = 3301;

    return fabrickIface->send(id, frameCnt, channel, type, data, dataLength);
}

bool AloraFabrickClient::sendAccelerometer(float x, float y, float z) {
    int xInt = (int)(x * 1000);
    int yInt = (int)(y * 1000);
    int zInt = (int)(z * 1000);

    long xLong = (xInt >= 0) ? xInt : (xInt + 65536);
    long yLong = (yInt >= 0) ? yInt : (yInt + 65536);
    long zLong = (zInt >= 0) ? zInt : (zInt + 65536);

    int dataLength = 6; // 3 bytes
    String xStr = FabrickUtils::addZeros(String(xLong, HEX), 2);
    String yStr = FabrickUtils::addZeros(String(yLong, HEX), 2);
    String zStr = FabrickUtils::addZeros(String(zLong, HEX), 2);

    String data = xStr + yStr + zStr;
    int frameCnt = 1;
    int channel = 0;
    int type = 3313;

    return fabrickIface->send(id, frameCnt, channel, type, data, dataLength);
}

bool AloraFabrickClient::sendGyrocopter(float x, float y, float z) {
    int xInt = (int)(x * 1000);
    int yInt = (int)(y * 1000);
    int zInt = (int)(z * 1000);

    long xLong = (xInt >= 0) ? xInt : (xInt + 65536);
    long yLong = (yInt >= 0) ? yInt : (yInt + 65536);
    long zLong = (zInt >= 0) ? zInt : (zInt + 65536);

    int dataLength = 6; // 3 bytes
    String xStr = FabrickUtils::addZeros(String(xLong, HEX), 2);
    String yStr = FabrickUtils::addZeros(String(yLong, HEX), 2);
    String zStr = FabrickUtils::addZeros(String(zLong, HEX), 2);

    String data = xStr + yStr + zStr;
    int frameCnt = 1;
    int channel = 0;
    int type = 3334;

    return fabrickIface->send(id, frameCnt, channel, type, data, dataLength);
}

bool AloraFabrickClient::sendMagnetometer(float x, float y, float z) {
    int xInt = (int)(x * 1000);
    int yInt = (int)(y * 1000);
    int zInt = (int)(z * 1000);

    long xLong = (xInt >= 0) ? xInt : (xInt + 65536);
    long yLong = (yInt >= 0) ? yInt : (yInt + 65536);
    long zLong = (zInt >= 0) ? zInt : (zInt + 65536);

    int dataLength = 6; // 3 bytes
    String xStr = FabrickUtils::addZeros(String(xLong, HEX), 2);
    String yStr = FabrickUtils::addZeros(String(yLong, HEX), 2);
    String zStr = FabrickUtils::addZeros(String(zLong, HEX), 2);

    String data = xStr + yStr + zStr;
    int frameCnt = 1;
    int channel = 0;
    int type = 3314;

    return fabrickIface->send(id, frameCnt, channel, type, data, dataLength);
}

bool AloraFabrickClient::sendAirQuality(int co2, int tvoc) {
    int dataLength = 8;

    String co2Str = FabrickUtils::addZeros(String(co2, HEX), 4);
    String tvocStr = FabrickUtils::addZeros(String(tvoc, HEX), 4);
    String data = co2Str + tvocStr;

    int frameCnt = 1;
    int channel = 0;
    int type = 3300;

    return fabrickIface->send(id, frameCnt, channel, type, data, dataLength);
}
