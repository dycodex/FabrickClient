#include <Arduino.h>
#include <Wire.h>
#include <FabrickLoRa.h>
#include <AloraFabrickClient.h>

// Include the header of Alora library.
#include <AloraSensorKit.h>


// nclude appropriate header for dealing with UART communication
// On ESP32 Arduino, the header file is HardwareSerial.h
// On Arduino UNO, it should be SoftwareSerial.h
#include <HardwareSerial.h>

// Initialize HardwareSerial object for LoRa shield
HardwareSerial loraSerial(1);

// Defines RX and TX pins that connected with LoRa shield
#define LORA_RX 33
#define LORA_TX 23


// Instantiate the AloraSensorKit class and global variable of Alora's SensorValue structure.
AloraSensorKit sensorKit;
SensorValues lastSensorData;

// Insantiate the FabrickLoRa and AloraFabrickClient object.
FabrickLoRa fabrick;
AloraFabrickClient aloraFabrick;

// Define the device ID of your device.
// This value is obtained from Fabrick device manager
#define FABRICK_DEVICE_ID "[Your device ID here]"

// Time tracker for sending data.
uint32_t temperatureSendMillis = 0;
uint32_t humiditySendMillis = 0;

void setup() {
    Serial.begin(9600);
    loraSerial.begin(9600, SERIAL_8N1, LORA_RX, LORA_TX);

    if (!fabrick.begin(&loraSerial)) {
        Serial.println("Failed to initialize communication with LoRa shield!");

        // don't continue the program if we fail
        while (1);
    }

    aloraFabrick.begin(&fabrick, FABRICK_DEVICE_ID);

    // initialize sensor kit
    sensorKit.begin();
}

void loop() {
    sensorKit.run();
    lastSensorData = sensorKit.getLastSensorData();

    if (millis() - temperatureSendMillis >= 15 * 1000) {
        // update the time tracker
        temperatureSendMillis = millis();

        // send temperature data from BME280 sensor
        if (aloraFabrick.sendTemperature(lastSensorData.T1)) {
            Serial.println("Success send temperature tx packet");
        } else {
            Serial.println("Failed to send temperature tx packet");
        }
    }

    if (millis() - humiditySendMillis >= 30 * 1000) {
        // update the time tracker
        humiditySendMillis = millis();

        // send humidity data from BME280 sensor
        if (aloraFabrick.sendHumidity(lastSensorData.H1)) {
            Serial.println("Success send humidity tx packet");
        } else {
            Serial.println("Failed to send humidity tx packet");
        }
    }
}
