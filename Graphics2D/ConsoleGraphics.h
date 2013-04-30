#pragma once
class ConsoleGraphics
{
public:
	ConsoleGraphics(void);
	ConsoleGraphics(int width, int height);
	~ConsoleGraphics(void);
	bool drawPoint(int x, int y);
private:
	int frameWidth, frameHeight;
	void initialize(int width, int height);
	void setupConsoleBuffer();
	void resetCursorPosition();
	void setCursorPosition(int x, int y);
};