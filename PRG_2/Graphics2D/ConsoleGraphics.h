#pragma once
class ConsoleGraphics
{
public:
	ConsoleGraphics(void);
	ConsoleGraphics(int width, int height);
	~ConsoleGraphics(void);
	bool drawPoint(int x, int y);
private:
	int frameWidth;
	int frameHeight;
};

