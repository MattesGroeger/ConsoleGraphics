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

bool ConsoleGraphics::drawPoint(unsigned int x, unsigned int y)
{
	return drawCharAtPosition(char(219), x, y);
}

bool ConsoleGraphics::undrawPoint(unsigned int x, unsigned int y)
{
	return drawCharAtPosition(char(32), x, y);
}

bool ConsoleGraphics::drawLine(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
	if (x1 == x2) // edge case: vertical lines
	{
		if (y1 > y2)
		{
			swapValues(&y1, &y2);
		}

		for (int y = y1; y <= y2; y++)
		{
			drawPoint(x1, y);
		}

		return true;
	}
	
	if (x1 > x2) // edge case: drawing backwards
	{
		swapValues(&x1, &x2);
		swapValues(&y1, &y2);
	}

	double m = (y2 - y1) / (x2 - x1);
	double n = y1 - (m * x1);

	for (int x = x1; x <= x2; x++)
	{
		double y = (m * x) + n;
		drawPoint(x, y);
	}

	return true;
}

void ConsoleGraphics::swapValues(unsigned int * a, unsigned int * b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

bool ConsoleGraphics::drawRectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
	drawLine(x1, y1, x2, y1);
	drawLine(x2, y1, x2, y2);
	drawLine(x2, y2, x1, y2);
	drawLine(x1, y2, x1, y1);

	return true;
}

bool ConsoleGraphics::drawCharAtPosition(char i, unsigned int x, unsigned int y)
{
	if (x >= frameWidth || y >= frameHeight)
		return false;
	
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

void ConsoleGraphics::setCursorPosition(unsigned int x, unsigned int y)
{
	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;

	SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
}