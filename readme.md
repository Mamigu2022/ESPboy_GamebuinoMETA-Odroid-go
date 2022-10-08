Port and refactoring of Gamebuino Meta game development library
for www.ESPboy.com project by RomanS

Allows you to recompile Gamebuino META games for ESPboy and play them with a very little modifications
The most common thing to do is to add "PROGMEM" macro for all the "const" data.
You have to take into account the absense of digital sound and music support for ESPboy in this ported lib. I'm not smart enough to do it properly )

Few games are also ported for ESPboy to be compiled and played.
Check GAME folder.

To get ported games work on the ESPboy, use Arduino Espressif ESP8266 SDK 3.0.2 and above and provide following Arduino IDE settings:
1. Board -> LOLIN (WeMos) D1 R2 & mini
2. CPU Frequency -> 160Mhz
3. Debug port -> disaled
4. Debug level -> none
5. IwIP variant -> v2 lower memory (no features)
6. C++ exceptions -> disabled
7. Stack protection -> disabled
8. SSL support -> basic SSL
9. MMU -> 32Kb cache & 32Kb IRAM (balanced)
10. Non 32bit Access -> Byte/Word access to IRAM/PROGMEM (very slow)  << !!! very important. without this setting you'll get permanent MCU resets



///
Welcome to the Gamebuino Meta official repository !
Get started [HERE](https://gamebuino.com/start)!
