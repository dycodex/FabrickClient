#include <Arduino.h>
#include <FabrickLoRa.h>

/**
 * Include appropriate header for dealing with UART communication
 * On ESP32 Arduino, the header file is HardwareSerial.h
 * On Arduino UNO, it should be SoftwareSerial.h
 */
#include <HardwareSerial.h>

/**
 * Use UART bus 1.
 */
HardwareSerial loraSerial(1);

/**
 * Defines RX and TX pins that connected with LoRa shield.
 */
#define LORA_RX 33
#define LORA_TX 23

/**
 * Insantiate the FabrickLoRa object.
 */
FabrickLoRa fabrick;

/**
 * Define the device ID of your device.
 * This value is obtained from Fabrick device manager
 */
#define FABRICK_DEVICE_ID "[your device ID here]"

void setup() {
    Serial.begin(9600);
    loraSerial.begin(9600, SERIAL_8N1, LORA_RX, LORA_TX);

    if (!fabrick.begin()) {
        Serial.pritnln("Failed to initialize communication with LoRa shield!");

        // don't continue the program if we fail
        while (1);
    }
}

void loop() {
    // you can use real data from sensor to replace the 23.45 value
    float temperature = 23.45;

    // convert to integer.
    int temperatureInt = (int)(temperature * 10);

    // handle negative values.
    long temperatureLong = (temperatureInt >= 0) ? temperatureInt : (temperatureInt + 65536);

    // convert to hex string and pad with zeros
    String temperatureData = String(temperatureLong, HEX);
    temperatureData = FabrickUtils::addZeros(temperatureData, 4);

    int frameCounter = 1; // amount of data sent
    int dataChannel = 0;
    int dataType = 3303;  // 3303 = temperature data type
    int dataLength = 4;

    bool result = fabrick.send(FABRICK_DEVICE_ID, frameCounter, dataChannel, dataType, temperatureData, dataLength);
    if (result) {
        Serial.println("Successfully send data");
    } else {
        Serial.println("Failed to send data");
    }

    delay(3000);
}
