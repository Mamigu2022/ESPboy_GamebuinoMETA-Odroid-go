/* 
	Editor: https://www.visualmicro.com/
			visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
			the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
			all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
			note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Gamebuino Meta, Platform=samd, Package=gamebuino
*/

#define ARDUINO 10805
#define ARDUINO_MAIN
#define F_CPU 48000000L
#define printf iprintf
#define __SAMD__
#define F_CPU 48000000L
#define ARDUINO 10805
#define ARDUINO_SAMD_ZERO
#define ARDUINO_ARCH_SAMD
#define __SAMD21G18A__
#define USB_VID 0x2341
#define USB_PID 0x804d
#define USBCON
//
//
void init_games();
void drawMeta();
void drawPL();
void drawLevel();
void draw_barre(bool openclose);
void draw_levelName();
void updateMeta();
void moveTimo();
void moveTima();
void loadLevel(int nv);
void nextLevel();

#include "pins_arduino.h" 
#include "variant.h" 
#include "arduino.h"
#include "projMeta.ino"
#include "drawMeta.ino"
#include "sound.ino"
#include "sprite.ino"
#include "updateMeta.ino"
