#pragma once

#define DIR_LEFT -1
#define DIR_RIGHT 1

#define COLOR_BLACK ((Color) 0x1063)
#define COLOR_DARKRED ((Color) 0x4126)
#define COLOR_DARKBLUE ((Color) 0x31ad)
#define COLOR_DARKGREY ((Color) 0x4a49)
#define COLOR_BROWN ((Color) 0x8266)
#define COLOR_DARKGREEN ((Color) 0x3324)
#define COLOR_RED ((Color) 0xd229)
#define COLOR_GREY ((Color) 0x738c)
#define COLOR_BLUE ((Color) 0x5bf9)
#define COLOR_ORANGE ((Color) 0xd3e5)
#define COLOR_LIGHTGREY ((Color) 0x84b4)
#define COLOR_GREEN ((Color) 0x6d45)
#define COLOR_PINK ((Color) 0xd553)
#define COLOR_LIGHTBLUE ((Color) 0x6e19)
#define COLOR_YELLOW ((Color) 0xdeab)
#define COLOR_WHITE ((Color) 0xdf7a)

struct Point
{
  int16_t x, y;
  Point(int16_t x = 0, int16_t y = 0) : x(x), y(y){}
};

struct Rect
{
  int16_t x, y, w, h;
  Rect(int16_t x = 0, int16_t y = 0, int16_t w = 0, int16_t h = 0) : x(x), y(y), w(w), h(h){}
};

inline int16_t clamp(int16_t x, int16_t a, int16_t b) { return x < a ? a : (x > b ? b : x); }

inline void debugLog(char* string)
{
	gb.display.setColor(COLOR_WHITE);
	gb.display.setCursor(1, (gb.display.height() / 2) - 3);
	gb.display.print(string);
}

inline void debugLog(int16_t number)
{
	gb.display.setColor(COLOR_WHITE);
	gb.display.setCursor(1, (gb.display.height() / 2) - 3);
	gb.display.print(number);
}