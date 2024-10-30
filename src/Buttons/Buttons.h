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

#ifndef _GAMEBUINO_META_BUTTONS_H_
#define	_GAMEBUINO_META_BUTTONS_H_

#include "../../config/config.h"
//#include <Adafruit_MCP23017.h> //to control buttons

#define PAD_LEFT        0x01
#define PAD_UP          0x02
#define PAD_DOWN        0x04
#define PAD_RIGHT       0x08
#define PAD_ACT         0x10
#define PAD_ESC         0x20
#define PAD_LFT         0x40
#define PAD_RGT         0x80
#define PAD_ANY         0xff
#define BTN_A       32
#define BTN_B       33
#define BTN_X			34
#define BTN_Y			35
#define BTN_MENU        13
#define BTN_HOME     0
namespace Gamebuino_Meta {

const PROGMEM uint8_t NUM_BTN = 8;

enum class Button : uint8_t {
	home  = 7,
	menu  = 6,
	b     = 5,
	a     = 4,
	up    = 3,
	right = 2,
	left  = 1,
	down  = 0,
};

class Buttons {
public:
	void begin();
	void update();
	bool pressed(Button button);
	bool released(Button button);
	bool held(Button button, uint16_t time);
	bool repeat(Button button, uint16_t period);
	uint16_t timeHeld(Button button);
	uint8_t states[NUM_BTN];
	
protected:
    //Adafruit_MCP23017 *thismcp;
};

} // namespace Gamebuino_Meta

using Gamebuino_Meta::Button;

const PROGMEM Button BUTTON_DOWN = Button::down;
const PROGMEM Button BUTTON_LEFT = Button::left;
const PROGMEM Button BUTTON_RIGHT = Button::right;
const PROGMEM Button BUTTON_UP = Button::up;
const PROGMEM Button BUTTON_A = Button::a;
const PROGMEM Button BUTTON_B = Button::b;
const PROGMEM Button BUTTON_MENU = Button::menu;
const PROGMEM Button BUTTON_HOME = Button::home;
const PROGMEM Button BUTTON_C = Button::menu;
const PROGMEM Button BUTTON_D = Button::home;

#endif	// _GAMEBUINO_META_BUTTONS_H_
