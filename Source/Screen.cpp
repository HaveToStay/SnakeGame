#include "Screen.h"
#include <conio.h>

const char* messages[] =
{
	"",
	"Failed GetStdHandle(): INVALID_HANDLE_VALUE",
	"Failed GetConsoleCursorInfo()",
	"Failed SetConsoleCursorInfo()",
	"Failed SetConsoleCursorPosition()"
};

const char* ScreenException::what()
{
	return messages[err];	
}

Screen::Screen()
{
	ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	if (ConsoleOutput == INVALID_HANDLE_VALUE)
		throw ScreenException(1);

	if(!GetConsoleCursorInfo(ConsoleOutput, &oldCursorInfo))
		throw ScreenException(2);
	curCursorInfo.dwSize = oldCursorInfo.dwSize;
	curCursorInfo.bVisible = oldCursorInfo.bVisible;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(ConsoleOutput, &csbi);
	oldTextAttr = csbi.wAttributes;
}

Screen::~Screen()
{
	SetConsoleCursorInfo(ConsoleOutput, &oldCursorInfo);
	SetConsoleTextAttribute(ConsoleOutput, oldTextAttr);
}

void Screen::cursor_show(bool visible)
{
	curCursorInfo.bVisible = visible;
	if (!SetConsoleCursorInfo(ConsoleOutput, &curCursorInfo))
		throw ScreenException(3);
}

void Screen::text_attr(WORD attr) {
	SetConsoleTextAttribute(ConsoleOutput, attr);
}

void Screen::pos(int x, int y, char ch) {
	COORD point;
	point.X = static_cast<SHORT>(x);
	point.Y = static_cast<SHORT>(y);
	if (!SetConsoleCursorPosition(ConsoleOutput, point))
		throw ScreenException(4);
	if (ch > 0)
		_putch(ch);
}

void Screen::pos_str(int x, int y, const char* str) {
	pos(x, y);
	_cprintf("%s", str);
}

void Screen::cls() {
	system("cls");
}