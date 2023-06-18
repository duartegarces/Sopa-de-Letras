#pragma once
#include <iostream>
#include <string>
#include "Point.h"
#include "Char.h"
#include "Word.h"

using namespace std;

struct matrix {
	int full=0;
	Char letra;
};

class Board
{
private:
	matrix** board_;
	int DimX;
	int DimY;
	Word* palavras;
	int countpalavras;
	int word_input[10]= { 0,0,0,0,0,0,0,0,0,0 };
	int word_discovered[10]= { 0,0,0,0,0,0,0,0,0,0 };

public:
	Board(void);
	void get_Dim(void);
	void new_board(void);
	void fill_board(void);
	void print_board(void);
	string theme_trans(int theme, string theme_w);
	void Get_Words(int theme);
	bool Check_Word(int pl, int pc, int i, int orientation);
	void Insert_Word(int theme);
	void Get_Count() { cout << countpalavras << endl; }
	bool Compare_words(string word_esc);
	bool end_game(void);
	void delete_(void);
	~Board();
};
