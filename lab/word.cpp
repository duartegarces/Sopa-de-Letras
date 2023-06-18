#include "Word.h"
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

Word::Word(void)
{
	palavra= "";
	Letters = 0;
	orientation = 0;
	sentido = 0;
	estado = 0;
	Position_start.SetX(0);
	Position_start.SetY(0);
	Position_end.SetX(0);
	Position_end.SetY(0);
}

Word::Word(Char* l, int t, string word, int o, int s, int state, Point p_i, Point p_f)
{
	Letters = l;
	tamanho_letters = t;
	palavra = word;
	orientation = o;
	sentido = s;
	estado = state;
	Position_start = p_i;
	Position_end = p_f;
}

Word::~Word()
{
}

void Word::Set_Word(string word)
{
	palavra = word;
	Set_Letters();
	//Set_Position();
	Set_Orientation();
}

void Word::Set_Letters()
{
	int i, j;
	i = palavra.length();
	tamanho_letters = i;
	Letters = new Char[i];
	for (j = 0; j < i; j++) {
		Letters[j].Set_Char(palavra[j]);
	}
}

void Word::Set_Position(int x_start, int y_start, int x_end, int y_end)
{
	Position_start.SetX(x_start);
	Position_start.SetY(y_start);
	Position_end.SetX(x_end);
	Position_end.SetY(y_end);
}

void Word::Set_Orientation(void)
{
	orientation = rand() % 4;
	sentido = rand() % 2;
}

void Word::View_Word() {
	int i;
	cout << "a palavra e " << palavra << "o seu tamanho e" << tamanho_letters << "e em vetor fica";
	for (i = 0; i < tamanho_letters; i++) {
		cout << " " << Letters[i].Get_Ch() << " ";
	}
	cout << endl;
}