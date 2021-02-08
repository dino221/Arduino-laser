#include "Adafruit_VL53L0X.h"

Adafruit_vl53l0x LOX = Adafruit_VL53L0X();

void setup () {
    Serial.begin(115200); // na Serial.begin(9600) ne radi, javlja se greska prilikom ocitavanja
    while(!Serial) {
    delay(1)
}
Serial.println("Adafruit VL53L0X test");   //Serial.print("Adafruit VL53L0X test");
if (!lox.begin()) {                             //if (lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));     //Serial.println(F("Failed to boot VL53L0X "));
    while(1);                                       //while(1);
}                                               //}
Serial.print(F("VL53L0X API Simple Ranging example \n\n"));
}

void loop() {
    VL53L0X_RangingMeasurementData_t measure;

    Serial.print("Reading a measurement...");
    lox.rangingTest(&measure, false);

    if (measure.RangeStatus != 4) {
        Serial.print("Distance (mm): ");
        Serial.println(measure.RangeMilliMeter);
    } else {
        Serial.println("out of range "); //max udaljenost koju moze ocitati iznosi 2 metra
    }
    delay(1000);
    // delay(10)
}
