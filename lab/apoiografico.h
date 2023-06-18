#ifndef _LABH_		//protectes from multiple including...
#define _LABH_		//... needs an #endif at bottom

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>


#define MY_COLOR_BLACK			0
#define MY_COLOR_DARK_BLUE		1
#define MY_COLOR_SOFT_GREEN		2
#define MY_COLOR_SOFT_BLUE		3
#define MY_COLOR_DARK_RED		4
#define MY_COLOR_PURPLE			5
#define MY_COLOR_DARK_YELLOW	6
#define MY_COLOR_GRAY			7
#define MY_COLOR_DARK_GRAY		8
#define MY_COLOR_CYAN			9
#define MY_COLOR_LIGTH_GREEN	10
#define MY_COLOR_LIGTH_BLUE		11
#define MY_COLOR_LIGTH_RED		12
#define MY_COLOR_PINK			13
#define MY_COLOR_LIGTH_YELLOW	14
#define MY_COLOR_WHITE			15

//altera a cor do texto e do fundo
void setColor(int foreGround, int backGround) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backGround * 16 + foreGround);
}
//altera a cor do texto, mantém a cor do fundo
void setForeColor(int foreGround) {
	int backGround = MY_COLOR_BLACK;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
	backGround = csbiInfo.wAttributes / 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backGround * 16 + foreGround);
}
//altera a cor do fundo, mantém a cor do texto
void setBackColor(int backGround) {
	int foreGround = MY_COLOR_BLACK;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
	foreGround = csbiInfo.wAttributes % 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backGround * 16 + foreGround);
}
//Color reset foreground color: white, background color: black
void resetColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MY_COLOR_BLACK * 16 + MY_COLOR_WHITE);
}

//coloca o Cursor na posicao X,Y
void gotoxy(int x, int y) {
	COORD c = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//desenha um retangulo com linhas duplas na posicao X,Y com as dimensoes Width e Height 
void showRectAt(int x, int y, int width, int height) {

	setlocale(LC_ALL, "C");
	int i;
	gotoxy(x, y);
	printf("%c", 218);
	for (i = 1; i < width; i++) {
		printf("%c", 196);
	}

	printf("%c", 191);
	gotoxy(x, height + y);
	printf("%c", 192);

	for (i = 1; i < width; i++) {
		printf("%c", 196);
	}

	printf("%c", 217);

	for (i = y + 1; i < height + y; i++) {
		gotoxy(x, i);
		printf("%c", 179);

		gotoxy(x + width, i);
		printf("%c", 179);

	}
	setlocale(LC_ALL, "");
}
//desenha um retangulo com linhas duplas na posicao X,Y com as dimensoes Width e Height, rodado 90º 
void show90RectAt(int x, int y, int width, int height) {
	showRectAt(x, y, height * 2, width / 2);
}
//show a char at a designated pposition
void showCharAt(int x, int y, char c) {
	setlocale(LC_ALL, "C");
	gotoxy(x, y);
	printf("%c", c);
	setlocale(LC_ALL, "");
}
//write a word verticaly at a designated position
void showVerticalWordAt(int x, int y, char c[], int charNumber) {
	setlocale(LC_ALL, "C");
	int i = 0;
	for (i = 0; i < charNumber; i++) {
		gotoxy(x, y + i);
		printf("%c", c[i]);
	}

	setlocale(LC_ALL, "");
}
//write a word horizontaly at a designated position
void printfAt(int x, int y, char c[]) {
	setlocale(LC_ALL, "C");
	gotoxy(x, y);
	printf("%s", c);
	setlocale(LC_ALL, "");
}

#endif
