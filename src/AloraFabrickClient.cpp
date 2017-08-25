#include "AloraFabrickClient.h"

AloraFabrickClient::AloraFabrickClient() {
}

AloraFabrickClient::~AloraFabrickClient() {
}

/**
 * Set the network interface for sending data & device ID.
 * @param netIface network interface for sending data.
 * @param deviceId device ID that is registered to Fabrick cloud.
 * @see FabrickNetIF
 */
void AloraFabrickClient::begin(FabrickNetIF* netIface, String deviceId) {
    fabrickIface = netIface;
    id = deviceId;
}

/**
 * Send temperature data through network interface to Fabrick.
 * @param temperatureInC temperature data in celcius unit.
 * @return indicates whether the interface got OK response or not. 
 */
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

/**
 * Send humidity data through network interface to Fabrick.
 * @param humidity humidity data.
 * @return indicates whether the interface got OK response or not.
 */
bool AloraFabrickClient::sendHumidity(float humidity) {
    int humInt = (int)(humidity * 2);
    int dataLength = 2; // 1 byte
    String data = FabrickUtils::addZeros(String(humInt, HEX), dataLength);

    int frameCnt = 1;
    int channel = 0;
    int type = 3304;

    return fabrickIface->send(id, frameCnt, channel, type, data, dataLength);
}

/**
 * Send pressure data thorugh the network interface.
 * @param pressure pressure data in hPa unit.
 * @return indicates whether the interface got OK response or not.
 */
bool AloraFabrickClient::sendPressure(float pressure) {
    int pressInt = (int)pressure;
    int dataLength = 4; // 2 bytes
    String data = FabrickUtils::addZeros(String(pressInt, HEX), dataLength);

    int frameCnt = 1;
    int channel = 0;
    int type = 3315;

    return fabrickIface->send(id, frameCnt, channel, type, data, dataLength);
}

/**
 * Send luminance data through the network interface.
 * @param luminance luminance data in lux unit.
 * @return indicates whether the interface got OK response or not.
 */
bool AloraFabrickClient::sendLux(float luminance) {
    int luminanceInt = (int)luminance;
    int dataLength = 6; // 3 bytes
    String data = FabrickUtils::addZeros(String(luminanceInt, HEX), dataLength);

    int frameCnt = 1;
    int channel = 0;
    int type = 3301;

    return fabrickIface->send(id, frameCnt, channel, type, data, dataLength);
}

/**
 * Send accelerometer data through the network interface.
 * @param x X axis of the accelerometer.
 * @param y Y axis of the accelerometer.
 * @param z Z axis of the accelerometer.
 * @return indicates whether the interface got OK response or not.
 */
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

/**
 * Send gyrocopter data through the network interface.
 * @param x X axis of the gyrocopter.
 * @param y Y axis of the gyrocopter.
 * @param z Z axis of the gyrocopter.
 * @return indicates whether the interface got OK response or not.
 */
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

/**
 * Send magnetometer data through the network interface.
 * @param x X axis of the magnetometer.
 * @param y Y axis of the magnetometer.
 * @param z Z axis of the magnetometer.
 * @return indicates whether the interface got OK response or not.
 */
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

/**
 * Send TVOC and CO2 data through the network interface.
 * @param co2 CO2 data.
 * @param tvoc TVOC data
 * @return indicates whether the interface got OK response or not.
 */
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
