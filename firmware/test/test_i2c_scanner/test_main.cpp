#include <Arduino.h>
#include <Wire.h>
#include <unity.h>

#define I2C_SDA_PIN 41
#define I2C_SCL_PIN 42

void test_i2c_scan() {
    Serial.println("Starting I2C Scan...");
    
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);  // <- Custom SDA/SCL pins

    byte count = 0;
    for (byte address = 1; address < 127; ++address) {
        Wire.beginTransmission(address);
        byte error = Wire.endTransmission();
        if (error == 0) {
            Serial.print("Found device at 0x");
            if (address < 16) Serial.print("0");
            Serial.println(address, HEX);
            count++;
        }
    }

    // Assert at least 1 device found (optional)
    TEST_ASSERT_MESSAGE(count > 0, "No I2C devices found!");
}

void setup() {
    Serial.begin(115200);
    delay(1000);  // Give time for serial monitor to attach

    UNITY_BEGIN();
    RUN_TEST(test_i2c_scan);
    UNITY_END();
}

void loop() {
}
