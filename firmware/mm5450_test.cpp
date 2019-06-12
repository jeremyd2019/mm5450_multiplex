#include <Arduino.h>
#include <assert.h>
#include <SPI.h>

#include "mm5450.h"

MultiplexMM5450 RED(9), YELLOW(8), GREEN(7);

void setup() {
	// put your setup code here, to run once:
	SPI.begin();
	RED.initialize();
	YELLOW.initialize();
	GREEN.initialize();
	// nice all-LEDs-on test pattern
	RED.assignLedRange(0, 1, 30, 0x3FFFFFFF);
	RED.assignLedRange(1, 1, 30, 0x3FFFFFFF);
	RED.assignLedRange(2, 1, 30, 0x3FFFFFFF);
}

void loop() {
	// put your main code here, to run repeatedly:
	MultiplexMM5450::process({&RED, &YELLOW, &GREEN});
	uint16_t frob = (millis() / 1000) & 0x1fff;
	RED.assignLed(0, 31, frob & 1);
	RED.assignLed(1, 31, frob & 2);
	RED.assignLed(2, 31, frob & 4);
	RED.assignLedRange(0, 18, 13, frob);
}
