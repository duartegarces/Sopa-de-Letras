#pragma once
#include <iostream>
#include <string>
#include "Point.h"
#include "Char.h"
#include "Word.h"
#include "tabuleiro.h"

using namespace std;

class jogador
{
private:
	string nome;
	int idade;
	int pontuação;
	int id;

public:
	jogador(void);
	void Set_nome(void);
	void view_stats(void);
	string play(void);
	void Guardar_pontuacao(void);
	void Set_id(void);
	void delete_(void);
	~jogador();
};

