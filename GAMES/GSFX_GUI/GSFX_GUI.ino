#include <Gamebuino-Meta.h>
#include "Gui.h"

Gui gui;

void setup()
{
  Serial.begin(115200);
	gb.begin();
	gui.Begin();
}

void loop()
{
	if (gb.update())
	{
		gui.Update();
		gui.Draw();
	}
}
