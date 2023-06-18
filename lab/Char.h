#pragma once
#include "Point.h"
#include <iostream>

using namespace std;

class Char
{
public:
	Char();
	void Rand(void);
	void View();
	void Get_Position(void);
	void Set_Char(char c);
	void tipo_Letra(void) { tipo = 'M'; }; 
	char Get_Ch() { return Ch; }
	void Set_Position(int x, int y);

	~Char();
private:
	char Ch;
	Point Position;
	char tipo;
	int ASCII;
};

