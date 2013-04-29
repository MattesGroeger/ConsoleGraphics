// Graphics_Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConsoleGraphics.h"
#include <string>
#include <iostream>

using namespace std;

void printChar(int index, char asci);

int _tmain(int argc, _TCHAR* argv[])
{
	ConsoleGraphics test;
	test.drawPoint(3, 4);
	//ConsoleGraphics *test = new ConsoleGraphics();

	// " " = 32
	// voll = 219
	// top = 223
	// bottom = 220
	/*
	for (int i = 32; i <= 254; i++)
	{
		printChar(i, i);
	}
	*/
	system("pause");

	return 0;
}

void printChar(int index, char asci)
{
	cout << index << ":\t" << asci << endl;
}