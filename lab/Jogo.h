#pragma once
#include <iostream>
#include <string>
#include "Point.h"
#include "Char.h"
#include "Word.h"
#include "tabuleiro.h"
#include "Jogador.h"
#include "cronometro.h"

using namespace std;

class Jogo
{
private:
	Board tabuleiro;
	jogador player;
public:
	Jogo(void);
	void executar(int theme, int new_player, int jogo_carregado);
	~Jogo(void);
};