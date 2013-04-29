#include "ConsoleGraphics.h"
#include <stdio.h>;
#include <Windows.h>;
#include <iostream>;

using namespace std;

CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
HANDLE hStdout;

ConsoleGraphics::ConsoleGraphics(void)
{
	setupConsoleBuffer();

	ConsoleGraphics(csbiInfo.dwSize.X, csbiInfo.dwSize.Y);
}

ConsoleGraphics::ConsoleGraphics(int width, int height)
{
	if (!hStdout)
		setupConsoleBuffer();

	frameWidth = width;
	frameHeight = height;

	printf("Created with size %i,%i\n", width, height);
}

ConsoleGraphics::~ConsoleGraphics(void)
{
}

void ConsoleGraphics::setupConsoleBuffer()
{
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);

//	width = (width > 0) ? width : csbiInfo.dwSize.X;
//	height = (height > 0) ? height : csbiInfo.dwSize.Y;
}

bool ConsoleGraphics::drawPoint(int x, int y)
{
	setCursorPosition(x, y);
	
	cout << char(219);

	resetCursorPosition();

	return true;
}

void ConsoleGraphics::resetCursorPosition()
{
	setCursorPosition(0, frameHeight + 1);

	cout << endl;
}

void ConsoleGraphics::setCursorPosition(int x, int y)
{
	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;

	SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
}