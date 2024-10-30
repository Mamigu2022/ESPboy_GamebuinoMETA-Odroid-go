/*
This file is part of the Gamebuino-Meta library,
Copyright (c) Aadalie 2017

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
 - Sorunome
*/

#include "Save.h"
#include "../../Gamebuino-Meta.h"

extern bool saveFlag;

#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif

#ifndef min
#define min(x,y) ((x < y) ? x : y)
#endif

namespace Gamebuino_Meta {
	
extern Gamebuino* gbptr;

#define SAVEHEADER_SIZE 10
#define SAVEFILE_PAYLOAD_START (SAVEHEADER_SIZE + (blocks * 5))

void Save::begin(const char* _savefile, const char* _checkbytes) {
//Serial.println("begin");
	savefile = _savefile;
	checkbytes = _checkbytes;
	
	defaults = 0;
	num_defaults = 0;
	blocks = SAVEBLOCK_NUM;
#if USE_SDFAT	
	SPIFFS.begin();
	//Serial.println();
#endif	
}


void Save::config(const SaveDefault* _defaults, uint16_t _num_defaults) {
//Serial.println("config1");
	config(SAVEBLOCK_NUM, _defaults, _num_defaults);
}

void Save::config(uint16_t _blocks, const SaveDefault* _defaults, uint16_t _num_defaults) {
//Serial.println("config2");
	blocks = _blocks > _num_defaults ? _blocks : _num_defaults;
	defaults = _defaults;
	num_defaults = _num_defaults;
}

void Save::error(const char *s) {
	gbptr->tft.fillScreen(0x0000);
	gbptr->tft.setCursor(0, 0);
	gbptr->tft.setColor(Color::red, Color::black);
	gbptr->tft.println("SAVE ERROR ");
	gbptr->tft.setColor(Color::white, Color::black);
	gbptr->tft.println(s);
	delay(3000);
	//LittleFS.remove(savefile);
}


SaveVar Save::getVarInfo(uint16_t i) {
//Serial.println("getVarInfo");
#if USE_SDFAT
    saveFlag = true;
	if (readOnly) {
		return {false, 0};
	}
	if (i >= blocks) {
		// Trying to access bad block...
		error("accessing non-existing block");
	}
	SaveVar s;
	//fs.SeekSet(SAVEHEADER_SIZE + i);
	//f.seek(SAVEHEADER_SIZE + i, SeekSet);
	f.seek(SAVEHEADER_SIZE + i,fs::SeekSet);
	uint8_t b;
	if (!f.read((uint8_t *)&b, 1)) {
		error("file I/O");
	}
	s.defined = (b & 0x80) ? true : false;
	s.type = b & 0x07;
	return s;
#else // USE_SDFAT
	return {false, 0};
#endif // USE_SDFAT
}

void Save::openFile() {
//Serial.println("openFile");
#if USE_SDFAT
    saveFlag = true;
	if (open) {
		return;
	}
	
	bool exists = LittleFS.exists(savefile);
	if (!exists) {
	    //Serial.println("he file doesn't exist yet, so let's create it");
		// the file doesn't exist yet, so let's create it
		f = LittleFS.open(savefile, "w+");
		f.write((const uint8_t *)checkbytes, 4);
		f.write((const uint8_t *)&blocks, 2); // write the amount of blocks
		
		// +4 because of 4-byte payload size
		for (uint32_t i = 0; i < (5*(uint32_t)blocks) + 4; i++) {
			f.write((uint8_t)0);
		}
		
		f.flush(); // make sure the file gets created
		f.close();
	}
	
	f = LittleFS.open(savefile, "r+");
	if (!f) {
		// eeeeeh, can't open it so we are read-only
		//Serial.println("can't open it so we are read-only");
		open = true;
		readOnly = true;
		return;
	}
	open = true;
	
	//f.rewind(); // rewind it so that we can read its properties
	f.seek(0, fs::SeekSet);
	// the file already exists, so time to read some properties!
	
	// first check that the checkbytes match!
	// we use the payload_size for this because that is just yet another free 4-byte buffer
	f.read((uint8_t *)&payload_size, 4);
	if (memcmp(&payload_size, checkbytes, 4) != 0) {
		error("Invalid save file");
	}
	uint16_t blocks_old;
	f.read((uint8_t *)&blocks_old, 2); // how many blocks do we have?
	f.read((uint8_t *)&payload_size, 4); // let's grab the payload size!
	
	if (blocks_old == blocks) {
		return; // everything is OK, nothing more to do
	}
	uint16_t blocks_new = blocks;
	blocks = blocks_old;
	if (blocks_old > blocks_new) {
		// we need to shrink the block size
		
		// first we delete the unneeded variables (due to payload maybe being off)
		for (uint16_t i = blocks_new; i < blocks_old; i++) {
			del(i);
		}
		
		// next we offset the blocks
		for (uint16_t i = 0; i < blocks_new; i++) {
			uint32_t b;
			//f.SeekSet(SAVEHEADER_SIZE + blocks_old + i*4);
			f.seek(SAVEHEADER_SIZE + blocks_old + i*4, fs::SeekSet);
			f.read((uint8_t *)&b, 4);
			//f.SeekSet(SAVEHEADER_SIZE + blocks_new + i*4);
			f.seek(SAVEHEADER_SIZE + blocks_new + i*4, fs::SeekSet);
			f.write((const uint8_t *)&b, 4);
		}
		
		// now we fix the payload
		for (uint32_t i = 0; i < payload_size; i++) {
			uint8_t b;
			f.seek(SAVEHEADER_SIZE + (blocks_old * 5) + i);
			f.read((uint8_t *)&b, 1);
			f.seek(SAVEHEADER_SIZE + (blocks_new * 5) + i);
			f.write((const uint8_t *)&b, 1);
		}
		//f.truncate(SAVEHEADER_SIZE + (blocks_new * 5) + payload_size);
	} else {
		// we need to grow the block size
		
		// first we grow the file by the desired amount
		//f.SeekSet(SAVEHEADER_SIZE + (blocks_old * 5) + payload_size);
		f.seek(SAVEHEADER_SIZE + (blocks_old * 5) + payload_size, fs::SeekSet);
		for (uint32_t i = 0; i < (uint32_t)(blocks_new - blocks_old)*5; i++) {
			f.write((uint8_t)0);
		}
		
		// next we shift the payload back
		for (uint32_t i = 0; i < payload_size; i++) {
			uint8_t b;
			f.seek(SAVEHEADER_SIZE + (blocks_old * 5) + (payload_size - i - 1), fs::SeekSet);
			f.read((uint8_t *)&b, 1);
			f.seek(SAVEHEADER_SIZE + (blocks_new * 5) + (payload_size - i - 1), fs::SeekSet);
			f.write((const uint8_t *)&b, 1);
		}
		
		// next we offset the blocks
		
		for (uint16_t i = 0; i < blocks_old; i++) {
			uint32_t b;
			//f.SeekSet(SAVEHEADER_SIZE + blocks_old + (blocks_old - i - 1)*4);
			f.seek(SAVEHEADER_SIZE + blocks_old + (blocks_old - i - 1)*4, fs::SeekSet);
			f.read((uint8_t *)&b, 4);
			f.seek(SAVEHEADER_SIZE + blocks_new + (blocks_old - i - 1)*4, fs::SeekSet);
			f.write((const uint8_t *)&b, 4);
		}
		
		// finally we nullate the new block metadata
		f.seek(SAVEHEADER_SIZE + blocks_old, fs::SeekSet);
		for (uint16_t i = blocks_old; i < blocks_new; i++) {
			f.write((uint8_t)0);
		}
	}
	blocks = blocks_new;
	f.seek(4, fs::SeekSet);
	f.write((const uint8_t *)&blocks_new, 2);
	f.flush();
#endif // USE_SDFAT
}




uint32_t Save::_get(uint16_t i) {
saveFlag = true;
//Serial.println("_get");
#if USE_SDFAT
	uint32_t val;
	//f.SeekSet(SAVEHEADER_SIZE + blocks + (4*i));
	f.seek(SAVEHEADER_SIZE + blocks + (4*i), fs::SeekSet);
	f.read((uint8_t *)&val, 4);
	return val;
#else // USE_SDFAT
	return 0;
#endif // USE_SDFAT
}

int32_t Save::get(uint16_t i) {
//Serial.println("get1");
	openFile();
	SaveVar s = getVarInfo(i);
	if (!s.defined) {
		for (uint16_t j = 0; j < num_defaults; j++) {
			if (defaults[j].i == i) {
				// we found our element!
				if (defaults[j].type != SAVETYPE_INT) {
					error("trying to get from a non-int type");
				}
				return defaults[j].val.ival;
			}
		}
		return 0;
	}
	if (s.type != SAVETYPE_INT) {
		error("trying to get from a non-int type");
	}
	return (int32_t)_get(i);
}

bool Save::get(uint16_t i, void* buf, uint32_t bufsize) {
//Serial.println("get2");
	openFile();
	SaveVar s = getVarInfo(i);
	if (!s.defined) {
		memset(buf, 0, bufsize);
		for (uint16_t j = 0; j < num_defaults; j++) {
			if (defaults[j].i == i) {
				// we found our element!
				if (defaults[j].type != SAVETYPE_BLOB) {
					error("trying to get from a non-blob type");
				}
				if (defaults[j].length && defaults[j].val.ptr) {
					memcpy(buf, defaults[j].val.ptr, min(bufsize, defaults[j].length));
				}
				break;
			}
		}
		return false;
	}
	if (s.type != SAVETYPE_BLOB) {
		error("trying to get from a non-blob type");
	}
#if USE_SDFAT
	uint32_t b = _get(i);
	
	// determine how many bytes to set
	uint32_t size;
	//f.SeekSet(SAVEFILE_PAYLOAD_START + b);
	f.seek(SAVEFILE_PAYLOAD_START + b, fs::SeekSet);
	f.read((uint8_t *)&size, 4);
	size = min(size, bufsize);
	
	// wwe already have the file pointer at the start
	
	// now finally perform the read
	f.read((uint8_t *)buf, size);
	return true;
#else // USE_SDFAT
	return false;
#endif // USE_SDFAT
}




void Save::_set(uint16_t i, uint32_t b) {
//Serial.println("_set");
#if USE_SDFAT
saveFlag = true;
	//f.SeekSet(SAVEHEADER_SIZE + blocks + (4*i));
	f.seek(SAVEHEADER_SIZE + blocks + (4*i), fs::SeekSet);
	f.write((const uint8_t *)&b, 4);
#endif // USE_SDFAT
}

bool Save::set(uint16_t i, int32_t num) {
//Serial.println("_et");
#if USE_SDFAT
saveFlag = true;
	openFile();
	if (readOnly) {
		return false;
	}
	SaveVar s = getVarInfo(i);
	if (s.defined && s.type != SAVETYPE_INT) {
		// trying to store an int in a non-int
		error("trying set to a non-int type");
	}
	for (uint16_t j = 0; j < num_defaults; j++) {
		if (defaults[j].i == i) {
			// we found our element!
			if (defaults[j].type != SAVETYPE_INT) {
				error("trying set to a non-int type");
			}
			break;
		}
	}
	if (!s.defined) {
		//f.SeekSet(SAVEHEADER_SIZE + i);
		f.seek(SAVEHEADER_SIZE + i, fs::SeekSet);
		f.write((uint8_t)(0x80 | SAVETYPE_INT));
	}
	_set(i, (uint32_t)num);
	f.flush();
	return true;
#else // USE_SDFAT
	return false;
#endif // USE_SDFAT
}

void Save::newBlob(uint16_t i, uint32_t size) {
//Serial.println("newBLOB");
#if USE_SDFAT
saveFlag = true;
	// set the int-table pointer
	_set(i, payload_size);
	
	//f.SeekSet(SAVEFILE_PAYLOAD_START + payload_size);
	f.seek(SAVEFILE_PAYLOAD_START + payload_size, fs::SeekSet);
	// write the size
	f.write((const uint8_t *)&size, 4);
	// now fill the payload with zeros
	for(uint32_t j = 0; j < size; j++) {
		f.write((uint8_t)0);
	}
	
	// aaand increase the payload size
	payload_size += size + 4; // +4 because size is stored in payload
	f.seek(6, fs::SeekSet);
	f.write((const uint8_t *)&payload_size, 4);
#endif // USE_SDFAT
}

bool Save::set(uint16_t i, char* buf) {
//Serial.println("set2");
	return set(i, (void*)buf, strlen(buf) + 1);
}

bool Save::set(uint16_t i, const char* buf) {
//Serial.println("set3");
	return set(i, (void*)buf, strlen(buf) + 1);
}

bool Save::set(uint16_t i, const void* buf, uint32_t bufsize) {
//Serial.println("set4");
	return set(i, (void*)buf, bufsize);
}

bool Save::set(uint16_t i, void* buf, uint32_t bufsize) {
//Serial.println("set5");
#if USE_SDFAT
	openFile();
	if (readOnly) {
		return false;
	}
	SaveVar s = getVarInfo(i);
	if (s.defined && s.type != SAVETYPE_BLOB) {
		// trying to store an int in a non-int
		error("trying set to a non-blob type");
	}
	uint32_t want_size = SAVECONF_DEFAULT_BLOBSIZE;
	for (uint16_t j = 0; j < num_defaults; j++) {
		if (defaults[j].i == i) {
			// we found our element!
			if (defaults[j].type != SAVETYPE_BLOB) {
				error("trying set to a non-blob type");
			}
			if (defaults[j].length) {
				want_size = defaults[j].length;
			} else {
				want_size = (uint32_t)defaults[j].val.ival;
			}
			break;
		}
	}
	
	if (!s.defined) {
		// first we create the blob entry
		f.seek(SAVEHEADER_SIZE + i, fs::SeekSet);
		f.write((uint8_t)(0x80 | SAVETYPE_BLOB));
		newBlob(i, want_size);
	}
	
	uint32_t b = _get(i);
	f.seek(SAVEFILE_PAYLOAD_START + b, fs::SeekSet);
	
	
	// determine how many bytes to set
	uint32_t size;
	f.read((uint8_t *)&size, 4);
	if (size != want_size) {
		// ok the size is different, so let's change this!
		del(i);
		return set(i, buf, bufsize);
	}
	size = min(size, bufsize);
	
	// we already seeked correctly
	
	// now finally perform the write
	f.write((const uint8_t *)buf, size);
	f.flush();
	return true;
#else // USE_SDFAT
	return false;
#endif // USE_SDFAT
}



void Save::del(uint16_t i) {
//Serial.println("Del");
#if USE_SDFAT
	openFile();
	if (readOnly) {
		return;
	}
	SaveVar s = getVarInfo(i);
	if (!s.defined) {
		return; // nothing to do!
	}
	
	// let's delete the entry first
	f.seek(SAVEHEADER_SIZE + i, fs::SeekSet);
	f.write((uint8_t)0);
	
	if (s.type == SAVETYPE_INT) {
		f.flush();
		return; // with ints that is all what is left to do
	}
	
	// ok, we have a blob, so we must get rid of the payload...
	uint32_t b = _get(i);
	
	// determine the size of the payload
	//f.SeekSet(SAVEFILE_PAYLOAD_START + b);
	f.seek(SAVEFILE_PAYLOAD_START + b, fs::SeekSet);
	uint32_t size;
	f.read((uint8_t *)&size, 4);
	size += 4; // we need to also delete the size bytes
	
	// now we need to loop all blocks and shift those with a payload pointer that is greater down a bit
	for (i = 0; i < blocks; i++) {
		s = getVarInfo(i);
		if (s.defined && s.type == SAVETYPE_BLOB) {
			uint32_t c = _get(i);
			if (c > b) {
				// we just adjust the pointer here, we do all the shifting later on
				c -= size;
				_set(i, c);
			}
		}
	}
	// ok now we actually need to shift the payload data
	for (uint32_t j = 0; j < (payload_size-b-size); j++) {
		uint8_t c;
		//f.SeekSet(SAVEFILE_PAYLOAD_START + b + size + j);
		f.seek(SAVEFILE_PAYLOAD_START + b + size + j, fs::SeekSet);
		f.read((uint8_t *)&c, 1);
		//f.SeekSet(SAVEFILE_PAYLOAD_START + b + j);
		f.seek(SAVEFILE_PAYLOAD_START + b + j, fs::SeekSet);
		f.write(c);
	}
	
	// now all that is left to do is to adjust the payload and filesize
	payload_size -= size;
	f.seek(6, fs::SeekSet);
	f.write((const uint8_t *)&payload_size, 4);
	//f.truncate(SAVEFILE_PAYLOAD_START + payload_size);
	f.flush();
#endif // USE_SDFAT
}

} // Gamebuino_Meta
