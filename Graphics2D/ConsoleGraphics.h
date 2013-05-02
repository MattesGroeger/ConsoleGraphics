#pragma once
class ConsoleGraphics
{
public:
	ConsoleGraphics(void);
	ConsoleGraphics(int width, int height);
	~ConsoleGraphics(void);
	bool drawPoint(unsigned int x, unsigned int y);
	bool undrawPoint(unsigned int x, unsigned int y);
	bool drawLine(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
private:
	int frameWidth, frameHeight;
	void initialize(int width, int height);
	void setupConsoleBuffer();
	void resetCursorPosition();
	void setCursorPosition(unsigned int x, unsigned int y);
	bool drawCharAtPosition(char i, unsigned int x, unsigned int y);
	void swapValues(unsigned int * a, unsigned int * b);
};