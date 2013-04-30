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

	initialize(csbiInfo.dwSize.X, csbiInfo.dwSize.Y);
}

ConsoleGraphics::ConsoleGraphics(int width, int height)
{
	setupConsoleBuffer();
	
	initialize(width, height);
}

ConsoleGraphics::~ConsoleGraphics(void)
{

}

void ConsoleGraphics::initialize(int width, int height)
{
	frameWidth = width;
	frameHeight = height;
}

void ConsoleGraphics::setupConsoleBuffer()
{
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
}

bool ConsoleGraphics::drawPoint(int x, int y)
{
	return drawCharAtPosition(char(219), x, y);
}

bool ConsoleGraphics::undrawPoint(int x, int y)
{
	return drawCharAtPosition(char(32), x, y);
}

bool ConsoleGraphics::drawCharAtPosition(char i, int x, int y)
{
	setCursorPosition(x, y);

	cout << i ;

	resetCursorPosition();

	return true;
}

void ConsoleGraphics::resetCursorPosition()
{
	setCursorPosition(0, frameHeight - 2);

	cout << endl;
}

void ConsoleGraphics::setCursorPosition(int x, int y)
{
	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;

	SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
}