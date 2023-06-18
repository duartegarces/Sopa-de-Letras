#pragma once
#include <iostream>
#include <string>
#include "Point.h"
#include "Char.h"


using namespace std;

class Word
{
public:
	Word(void);
	Word(Char*, int, string, int, int, int, Point, Point);

	void Set_Word(string word);
	void Set_Position(int x_start, int y_start, int x_end, int y_end);
	void Set_Letters(void);
	void Set_Orientation(void);
	void Set_Direction(int s) { sentido = s; }
	void Set_Estado(int state) { estado = state; };
	void View_Word(void);
	string Get_Word() { return palavra; };
	int Get_tamanho() { return tamanho_letters; };
	int Get_orientation() { return orientation; }
	Char Get_Letter(int p) { return Letters[p]; }
	char Get_Letter_Ch(int p) { return Letters[p].Get_Ch(); }
	int Get_Direction() { return sentido; }

	~Word();

private:
	Char* Letters;
	int tamanho_letters;
	string palavra;
	int orientation;
	int sentido;
	int estado;
	Point Position_start;
	Point Position_end;
};

