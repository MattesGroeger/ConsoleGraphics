#include "ConsoleGraphics.h"
#include <stdio.h>;

ConsoleGraphics::ConsoleGraphics(void)
{
}


ConsoleGraphics::~ConsoleGraphics(void)
{
}

bool ConsoleGraphics::drawPoint(int x, int y)
{
	printf("Draw point at (%i,%i)\n", x, y);
	return true;
}