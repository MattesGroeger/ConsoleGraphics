#include "ConsoleGraphics.h"
#include <stdio.h>;
#include <Windows.h>;


ConsoleGraphics::ConsoleGraphics(void)
{
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);

	ConsoleGraphics(csbiInfo.dwSize.X, csbiInfo.dwSize.Y);
}

ConsoleGraphics::ConsoleGraphics(int width, int height)
{
	frameWidth = width;
	frameHeight = height;

	printf("Created with size %i,%i\n", width, height);
}

ConsoleGraphics::~ConsoleGraphics(void)
{
}

bool ConsoleGraphics::drawPoint(int x, int y)
{
	printf("Draw point at (%i,%i)\n", x, y);
	return true;
}