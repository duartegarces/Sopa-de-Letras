#include "Char.h"
#include <iostream>

Char::Char()
{
	Ch = 0;
	Position.SetX(0);
	Position.SetY(0);
	tipo = 0;
	ASCII = 0;
}

Char::~Char()
{
}

void Char::Rand()
{
	Ch = rand() % 26 + 'A';
	ASCII = Ch;
}

void Char::Set_Char(char c)
{
	Ch = c;
	tipo = 'M';
	ASCII = c;
}
 
void Char::View()
{
	cout << "letra= " << Get_Ch() << "e a sua posição é ";
	Position.Show();
}

void Char::Get_Position()
{
	if (Position.Ask2Set())
		cout << "Valid point";
	else
		cout << "Invalid point";
}

void Char::Set_Position(int x, int y)
{
	Position.SetX(x);
	Position.SetY(y);
}