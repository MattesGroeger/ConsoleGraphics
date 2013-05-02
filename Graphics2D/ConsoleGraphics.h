#pragma once
class ConsoleGraphics
{
public:
	ConsoleGraphics(void);
	ConsoleGraphics(int width, int height);
	~ConsoleGraphics(void);
	bool drawPoint(unsigned int x, unsigned int y);
	bool undrawPoint(unsigned int x, unsigned int y);
private:
	int frameWidth, frameHeight;
	void initialize(int width, int height);
	void setupConsoleBuffer();
	void resetCursorPosition();
	void setCursorPosition(unsigned int x, unsigned int y);
	bool drawCharAtPosition(char i, unsigned int x, unsigned int y);
};