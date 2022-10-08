/*
This file is part of the Gamebuino-Meta library,
Copyright (c) Aadalie 2017

Authors:
 - Sorunome
*/

#include "Save.h"


namespace Gamebuino_Meta {

void Save::begin() {
 char getCH1, getCH2;
  uint32_t numOfBlocks=SAVEBLOCK_NUM*32;
  EEPROM.begin(numOfBlocks+2);
  EEPROM.get(0, getCH1);
  EEPROM.get(1, getCH2);
  if (getCH1 != 'G' || getCH2 != 'U'){
      for(uint16_t i=2; i<numOfBlocks*4; i++)
        EEPROM.put(i, (uint8_t)0);
        EEPROM.put(0, 'G');
        EEPROM.put(1, 'U');
        EEPROM.commit();  }   
};


void Save::config(const SaveDefault* _defaults) {
}

void Save::config(const SaveDefault* _defaults, uint16_t _num_defaults) {
//	config(SAVEBLOCK_NUM, _defaults, _num_defaults);
}

void Save::config(uint16_t _blocks, const SaveDefault* _defaults, uint16_t _num_defaults) {
//	blocks = _blocks > _num_defaults ? _blocks : _num_defaults;
//	defaults = _defaults;
//	num_defaults = _num_defaults;
}


int32_t Save::get(uint16_t i) {
  uint32_t num;
  EEPROM.get((i*32)+2, num);
  return (num);
};


bool Save::set(uint16_t i, int32_t num) {
  EEPROM.put((i*32)+2, num);
  EEPROM.commit();
  return true;
};


void Save::get(uint16_t i, char *num) {
  for(uint16_t j=0; j<strlen(num)+1; j++){
    EEPROM.get(i*32+2+j, num[j]);  
    delay(0);}
}

bool Save::set(uint16_t i, char* num) {
  for(uint16_t j=0; j<strlen(num)+1; j++){ 
    EEPROM.put(i*32+2+j, num[j]);
    delay(0);}
  EEPROM.commit();
  return true;
};



bool Save::get(uint16_t i, uint8_t* buf, uint32_t bufsize){
  for(uint16_t j=0; j<bufsize; j++){
    buf[j]=EEPROM.read(i*32+2+j);
    delay(0);}
  return true;
};



bool Save::set(uint16_t i, uint8_t* buf, uint32_t bufsize){
  for(uint16_t j=0; j<bufsize; j++){
    EEPROM.write(i*32+2+j, buf[j]);
    delay(0);}
  EEPROM.commit();
  return true;
};



void Save::del(uint16_t i) {
  uint8_t arr[32];
  memset(&arr[0],0,sizeof(arr));
  EEPROM.put((i*32)+2, arr);
  EEPROM.commit();
};

} // Gamebuino_Meta
