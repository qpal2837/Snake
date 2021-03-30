#include "Draw.h"

Draw& Draw::getDraw() {
	static Draw draw;
	return draw;
}
Draw::Draw() {
}

void Draw::writeChar(COORD point, WORD color, const char* content) {
	HANDLE outPut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(outPut, { point.X * 2,point.Y });
	SetConsoleTextAttribute(outPut, color);
	printf(content);
}
void Draw::writeInt(COORD point, WORD color, int content) {
	HANDLE outPut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(outPut, { point.X * 2,point.Y });
	SetConsoleTextAttribute(outPut, color);
	printf("%d",content);
}

void Draw::hideCursor(bool hide) {
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info = { 1, FALSE };
	SetConsoleCursorInfo(output, &cursor_info);
}
