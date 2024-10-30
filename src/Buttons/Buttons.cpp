/*
This file is part of the Gamebuino-Meta library,
Copyright (c) Aadalie 2014, 2016-2017

This is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License (LGPL)
as published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.

This is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License (LGPL) for more details.

You should have received a copy of the GNU Lesser General Public
License (LGPL) along with the library.
If not, see <http://www.gnu.org/licenses/>.

Authors:
 - Aurelien Rodot
 - Sorunome
*/

#include "Buttons.h"
#include <Arduino.h>

namespace Gamebuino_Meta {


void Buttons::begin() { 
	Serial.begin(115200);
  //thismcp=mcp_;
 // for (int i=0;i<8;i++){  
    // thismcp->pinMode(i, INPUT);
     //thismcp->pullUp(i, HIGH);
 // }
    pinMode(BTN_MENU, INPUT_PULLUP);
    pinMode(BTN_HOME, INPUT_PULLUP);
	pinMode(BTN_B, INPUT_PULLUP);
	pinMode(BTN_A, INPUT_PULLUP);
	//pinMode(TTGO_UP, INPUT);
	//pinMode(TTGO_RIGHT, INPUT_PULLDOWN);
	pinMode(BTN_X , INPUT_PULLDOWN);
	pinMode(BTN_Y , INPUT_PULLDOWN);
}


/*
 * reads each button states and store it
 */
void Buttons::update() {
	uint8_t butstate = 255;
	uint8_t readstate;
	int joyX = analogRead(BTN_X);
    int joyY = analogRead(BTN_Y);
	if (joyY > 2048 + 1024) bitClear(butstate, (uint8_t)BUTTON_UP);
    else if (joyY > 1024)   bitClear(butstate, (uint8_t)BUTTON_DOWN);
    if (joyX > 2048 + 1024) bitClear(butstate, (uint8_t)BUTTON_LEFT);
    else if (joyX > 1024)   bitClear(butstate, (uint8_t)BUTTON_RIGHT);
	if (!digitalRead(BTN_A))      bitClear(butstate, (uint8_t)BUTTON_A);
    if (!digitalRead(BTN_B)) 	  bitClear(butstate, (uint8_t)BUTTON_B);
	if (!digitalRead(BTN_MENU))   bitClear(butstate, (uint8_t)BUTTON_MENU);
    if (!digitalRead(BTN_HOME))   bitClear(butstate, (uint8_t)BUTTON_HOME); 
	//readstate = ~(thismcp->readGPIOAB() & 255);
    //gamebuino uses inverted logic! 0 - means pressed and 1 - means unpressed
	//if (readstate&PAD_LEFT) 	bitClear(butstate, (uint8_t)BUTTON_LEFT);
	//if (readstate&PAD_RIGHT) 	bitClear(butstate, (uint8_t)BUTTON_RIGHT);
	//if (readstate&PAD_UP) 		bitClear(butstate, (uint8_t)BUTTON_UP);
	//if (readstate&PAD_DOWN) 	bitClear(butstate, (uint8_t)BUTTON_DOWN);
	//if (readstate&PAD_ACT) 		bitClear(butstate, (uint8_t)BUTTON_A);
	//if (readstate&PAD_ESC) 		bitClear(butstate, (uint8_t)BUTTON_B); 
	//if (readstate&PAD_LFT) 		bitClear(butstate, (uint8_t)BUTTON_HOME); 
	//if (readstate&PAD_RGT)	 	bitClear(butstate, (uint8_t)BUTTON_MENU); 

	uint8_t buttonsData = butstate;
	//Serial.println(butstate);
	for (uint8_t thisButton = 0; thisButton < NUM_BTN; thisButton++) {
		bool pressed = !bitRead(buttonsData, thisButton);
		//Serial.println(pressed);
		if (pressed) { //if button pressed
			if (states[thisButton] < 0xFE) { // we want 0xFFFE to be max value for the counter
				states[thisButton]++; //increase button hold time
			} else if (states[thisButton] == 0xFF) { // if we release / hold again too fast
				states[thisButton] = 1;
			}
		} else {
			if (states[thisButton] == 0) {//button idle
				continue;
			}
			if (states[thisButton] == 0xFF) {//if previously released
				states[thisButton] = 0; //set to idle
			} else {
				states[thisButton] = 0xFF; //button just released
			}
		}
		
	}
}

/*
 * Returns true when 'button' is pressed.
 * The button has to be released for it to be triggered again.
 */
bool Buttons::pressed(Button button) {
	return states[(uint8_t)button] == 1;
}

/*
 * return true if 'button' is released
 */
bool Buttons::released(Button button) {
	return states[(uint8_t)button] == 0xFF;
}

/**
 * returns true ONCE when 'button' is held for 'time' frames
 * @param button The button's ID
 * @param time How much frames button must be held, between 1 and 254.
 * @return true when 'button' is held for 'time' frames
 */
bool Buttons::held(Button button, uint16_t time){
	return states[(uint8_t)button] == (time+1);
}

/**
 * returns true every 'period' frames when 'button' is held
 * @param button The button's ID
 * @param period How much frames button must be held, between 1 and 254.
 * @return true if the button is held for the given time
 */
bool Buttons::repeat(Button button, uint16_t period) {
	if (period <= 1) {
		if ((states[(uint8_t)button] != 0xFFFF) && (states[(uint8_t)button])) {
			return true;
		}
	} else {
		if ((states[(uint8_t)button] != 0xFFFF) && ((states[(uint8_t)button] % period) == 1)) {
			return true;
		}
	}
	return false;
}

/**
 * 
 * @param button The button's ID
 * @return The number of frames during which the button has been held.
 */
uint16_t Buttons::timeHeld(Button button){
	if(states[(uint8_t)button] != 0xFFFF) {
		return states[(uint8_t)button];
	} else {
		return 0;
	}
}


} // namespace Gamebuino_Meta
