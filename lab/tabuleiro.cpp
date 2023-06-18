#include "tabuleiro.h"
#include <string.h>
#include <iostream>
#include <fstream >

using namespace std;

Board::Board(void) {
	board_= 0;
	palavras = new Word[10];
	DimX=0;
	DimY=0;;
	countpalavras=0;
}

void Board::get_Dim(void) {
	cout << "Indique o número de linhas para a sopa de letras:" << endl;  // inserir um minimo para o tamanho
	cin >> DimX;
	cout << "Indique o número de colunas para a sopa de letras:"<< endl;
	cin >> DimY;
	while (DimX < 15 || DimY < 15) {
		cout << "Introduziu uma dimensão errada, por favor volte a inserir as dimensões." << endl;
		cout << "Indique o número de linhas para a sopa de letras:" << endl;  // inserir um minimo para o tamanho
		cin >> DimX;
		cout << "Indique o número de colunas para a sopa de letras:" << endl;
		cin >> DimY;
	}
}

void Board::new_board(void) {
	board_ = new struct matrix* [DimX];
	for (int i = 0; i < DimX; ++i)
		board_[i] = new struct matrix[DimY];
}

void Board::fill_board(void) {
	int i, j;
	for (i = 0; i < DimX; i++) {
		for (j = 0; j < DimY; j++) {
			board_[i][j].letra.Rand();
			board_[i][j].letra.Set_Position(i, j);
			board_[i][j].full = 0;
		}
	}
}

void Board::print_board(void) {
	int i, j;
	for (i = 0; i < DimX; i++) {
		for (j = 0; j < DimY; j++) {
			cout << board_[i][j].letra.Get_Ch() << " ";
		}
		cout << endl;
	}
}

string Board::theme_trans(int theme, string theme_w) {
	switch (theme) {
	case 1:
		theme_w = "DISTRITOS";
		break;
	case 2:
		theme_w = "MARCAS DE CARROS";
		break;
	case 3:
		theme_w = "PAÍSES";
		break;
	case 4:
		theme_w = "PEÇAS DE ROUPA E ACESSÓRIOS";
		break;
	default:
		break;
	}
	return theme_w;
}

void Board::Get_Words(int theme) {
	ifstream is; // objecto os para abrir o ficheiro em modo de leitura
	string palavra;
	string theme_w;
	int i;
	theme_w = theme_trans(theme, theme_w);
	is.open("palavras.txt");
	if (!is) {
		exit(1);
	}
	while (!is.eof()) {
		getline(is, palavra);
		if (palavra.compare(theme_w) == 0) {
			for (i = 0; i < 10; i++) {
				getline(is, palavra);
				palavras[i].Set_Word(palavra);
				//palavras[i].View_Word(palavra);
			}
		}
	}
	is.close();
}

bool Board::Check_Word(int pl, int pc, int i, int orientation) {
	int j;
	switch (orientation) {
	case 0:  //horiz
		for (j = 0; j < (palavras[i].Get_tamanho()); j++) {
			if ((board_[pl][pc + j].letra.Get_Ch() != palavras[i].Get_Letter_Ch(j)) && (board_[pl][pc + j].full == 1)) {
				return false;
			}
		}
		return true;
		break;
	case 1: // vert
		for (j = 0; j < (palavras[i].Get_tamanho()); j++) {
			if ((board_[pl + j][pc].letra.Get_Ch() != palavras[i].Get_Letter_Ch(j)) && (board_[pl + j][pc].full == 1)) {
				return false;
			}
		}
		return true;
		break;
	case 2://diag 1
		for (j = 0; j < (palavras[i].Get_tamanho()); j++) {
			if ((board_[pl + j][pc + j].letra.Get_Ch() != palavras[i].Get_Letter_Ch(j)) && (board_[pl + j][pc + j].full == 1)) {
				return false;
			}
		}
		return true;
		break;
	case 3://diag 2
		for (j = 0; j < (palavras[i].Get_tamanho()); j++) {
			if ((board_[DimX - 1 - pl - j][pc + j].letra.Get_Ch() != palavras[i].Get_Letter_Ch(j)) && (board_[DimX - 1 - pl - j][pc + j].full == 1)) {
				return false;
			}
		}
		return true;
		break;
	}
}

void Board::Insert_Word(int theme) {
	int i, j, pl, pc, count;
	Get_Words(theme);
	for (i = 0; i < 10; i++) {
		count = 0;
		while (count < 20) {
			switch (palavras[i].Get_orientation()) {
			case 0:   //horiz
				pl = rand() % DimX;
				pc = rand() % (DimY - palavras[i].Get_tamanho() + 1);
				if (Check_Word(pl, pc, i, palavras[i].Get_orientation())) {
					count = 20;
					word_input[i] = 1;
					countpalavras += 1;
					if ((palavras[i].Get_Direction()) == 0) {
						for (j = 0; j < (palavras[i].Get_tamanho()); j++) {
							board_[pl][pc + j].letra.Set_Char(palavras[i].Get_Letter_Ch(j));
							board_[pl][pc + j].full = 1;
						}
					}
					else {
						for (j = 0; j < (palavras[i].Get_tamanho()); j++) {
							board_[pl][pc + j].letra.Set_Char(palavras[i].Get_Letter_Ch(palavras[i].Get_tamanho() - j - 1));
							board_[pl][pc + j].full = 1;
						}
					}
					palavras[i].Set_Position(pl, pc, pl, (pc + palavras[i].Get_tamanho() - 1));
				}
				break;
			case 1:   //vert
				pc = rand() % DimX;
				pl = rand() % (DimY - palavras[i].Get_tamanho() + 1);
				if (Check_Word(pl, pc, i, palavras[i].Get_orientation())) {
					count = 20;
					word_input[i] = 1;
					countpalavras += 1;
					if ((palavras[i].Get_Direction()) == 0) {
						for (j = 0; j < (palavras[i].Get_tamanho()); j++) {
							board_[pl + j][pc].letra.Set_Char(palavras[i].Get_Letter_Ch(j));
							board_[pl + j][pc].full = 1;
						}
					}
					else {
						for (j = 0; j < (palavras[i].Get_tamanho()); j++) {
							board_[pl + j][pc].letra.Set_Char(palavras[i].Get_Letter_Ch(palavras[i].Get_tamanho() - j - 1));
							board_[pl + j][pc].full = 1;
						}
					}
					palavras[i].Set_Position(pl, pc, pl + palavras[i].Get_tamanho() - 1, pc);
				}
				break;
			case 2:   //diag 1
				pc = rand() % (DimX - palavras[i].Get_tamanho() + 1);
				pl = rand() % (DimY - palavras[i].Get_tamanho() + 1);
				if (Check_Word(pl, pc, i, palavras[i].Get_orientation())) {
					count = 20;
					word_input[i] = 1;
					countpalavras += 1;
					if ((palavras[i].Get_Direction()) == 0) {
						for (j = 0; j < (palavras[i].Get_tamanho()); j++) {
							board_[pl + j][pc + j].letra.Set_Char(palavras[i].Get_Letter_Ch(j));
							board_[pl + j][pc + j].full = 1;
						}
					}
					else {
						for (j = 0; j < (palavras[i].Get_tamanho()); j++) {
							board_[pl + j][pc + j].letra.Set_Char(palavras[i].Get_Letter_Ch(palavras[i].Get_tamanho() - j - 1));
							board_[pl + j][pc + j].full = 1;
						}
					}
					palavras[i].Set_Position(pl, pc, pl + palavras[i].Get_tamanho() - 1, pc + palavras[i].Get_tamanho() - 1);
				}
				break;
			case 3: //diag 2
				pc = rand() % (DimX - palavras[i].Get_tamanho() + 1);
				pl = rand() % (DimY - palavras[i].Get_tamanho() + 1);
				if (Check_Word(pl, pc, i, palavras[i].Get_orientation())) {
					count = 20;
					word_input[i] = 1;
					countpalavras += 1;
					if ((palavras[i].Get_Direction()) == 0) {
						for (j = 0; j < (palavras[i].Get_tamanho()); j++) {
							board_[DimX - 1 - pl - j][pc + j].letra.Set_Char(palavras[i].Get_Letter_Ch(j));
							board_[DimX - 1 - pl - j][pc + j].full = 1;
						}
					}
					else {
						for (j = 0; j < (palavras[i].Get_tamanho()); j++) {
							board_[DimX - 1 - pl - j][pc + j].letra.Set_Char(palavras[i].Get_Letter_Ch(palavras[i].Get_tamanho() - j - 1));
							board_[DimX - 1 - pl - j][pc + j].full = 1;
						}
					}
					palavras[i].Set_Position(DimX - 1 - pl, pc, DimX - 1 - pl - palavras[i].Get_tamanho() - 1, pc + palavras[i].Get_tamanho() - 1);
				}
				break;
			}
			count++;
		}
	}
}

bool Board::Compare_words(string word_esc)
{
	int i;
	for (i = 0; i < 10; i++) {
		if (word_esc.compare(palavras[i].Get_Word()) == 0 && word_input[i] == 1) {
			word_discovered[i] = 1;
			return true;
		}
	}
	return false;	
}

bool Board::end_game() 
{
	int i;
	for (i = 0; i < 10; i++) {
		if (word_discovered[i] != 1) {
			return false;
		}
	}
	return true;
}

void Board::delete_()
{
	int i;
	delete[] board_;
	delete[] palavras;
	countpalavras = 0;
	DimX = 0;
	DimY = 0;
	for (i = 0; i < 10; i++) {
		word_discovered[i] = 0;
		word_input[i] = 0;
	}
}

Board::~Board() 
{
}