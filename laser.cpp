#include "Adafruit_VL53L0X.h"
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
	Serial.begin(115200);
	while(!Serial) {
		delay(1);
	}

	Serial.println("Adafruit VL53LOX test");
	if(!lox.begin()) {
		Serial.println(F("Failed to boot VL53LOX"));
	}
	//power
	Serial.print(F("VL53LOX API Simple Ranging example \n\n"));
	}

void loop() {
	VL53L0X_RangingMeasurement_t measure;

	Serial.print(@Reading a measurement .... @);
	lox.rangingTest(&measure, false);

	if(measure.RangeStatus != 4) {
		Serial.print("Distance(mm): ");
	} else {
		Serial.print("Out of range");
	}
	delay(1000);
}
	
