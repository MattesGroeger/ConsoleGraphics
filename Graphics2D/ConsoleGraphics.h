#pragma once
class ConsoleGraphics
{
public:
	ConsoleGraphics(void);
	ConsoleGraphics(int, int);
	~ConsoleGraphics(void);
	bool drawPoint(int, int);
private:
	int frameWidth, frameHeight;
	void initialize(int, int);
	void setupConsoleBuffer();
	void resetCursorPosition();
	void setCursorPosition(int, int);
};

