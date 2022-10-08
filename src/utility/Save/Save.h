/*
This file is part of the Gamebuino-Meta library,
Copyright (c) Aadalie 2017

Authors:
 - Sorunome
*/

#ifndef _GAMEBUINO_META_SAVE_H_
#define _GAMEBUINO_META_SAVE_H_

#include "../../config/config.h"
#include <ESP_EEPROM.h>

namespace Gamebuino_Meta {

struct SaveDefault {
	const uint16_t i;
	const uint8_t type;
	const union {
		const int32_t ival;
		const void *ptr;
	} val;
	const uint32_t length;
//	SaveDefault(const uint8_t i, const uint8_t type, const int32_t ival): i(i), type(type), val{.ival=ival}, length(0){};
//	SaveDefault(const uint8_t i, const uint8_t type, const void* ptr, const uint8_t length): i(i), type(type), val{.ptr=ptr}, length(length){};
};

class Save {
public:
	void begin();
	
	void config(const SaveDefault* _defaults);
	void config(const SaveDefault* _defaults, uint16_t _num_defaults);
	void config(uint16_t _blocks, const SaveDefault* _defaults, uint16_t _num_defaults);

	int32_t get(uint16_t i);
	bool set(uint16_t i, int32_t num);
	void get(uint16_t i, char* num);
	bool set(uint16_t i, char* num);
	void del(uint16_t i);
	bool get(uint16_t i, uint8_t* buf, uint32_t bufsize);
	bool set(uint16_t i, uint8_t* buf, uint32_t bufsize);
	
private:
    uint32_t numOfBlocks;
};

} // namsepace Gamebuino_Meta


using Gamebuino_Meta::SaveDefault;

#endif // _GAMEBUINO_META_SAVE_H_
