#include "Jogo.h"
#include <string.h>
#include <iostream>

using namespace std;

Jogo::Jogo() 
{
}

void Jogo::executar(int theme, int new_player, int jogo_carregado)
{
	int sair = 0;
	char lint;
	string palavraesc;
	if (new_player == 1) {
		player.Set_nome();
	}
	system("cls");
	if (jogo_carregado == 0) {
		tabuleiro.get_Dim();
		tabuleiro.new_board();
		tabuleiro.fill_board();
		//tabuleiro.print_board();
		tabuleiro.Insert_Word(theme);
	}
	while (sair == 0) {
		system("cls");
		tabuleiro.print_board();
		if (tabuleiro.end_game()) {
			//cout fim do jogo
		}
		else {
			palavraesc = player.play();
			if (!palavraesc.empty()) {
				if (tabuleiro.Compare_words(player.play())) {
					cout << "Certo!" << endl;
				}
				else {
					cout << "A palavra não existe na matriz." << endl;
				}
				//tabuleiro.Get_Count();
			}
			else {
				cout << "Deseja começar um novo jogo, sair ou guardar jogo e sair? 's' para começar um novo jogo, 'g' para guardar jogo ou 'e' para sair" << endl;
				cin >> lint;
				if (lint == 'y' || lint == 'Y') {
					//perguntar tema
					tabuleiro.delete_();
					player.delete_();
					executar(theme, 0, 0);
				}
				else if (lint == 'e' || lint == 'E') {
					sair = 1;
					tabuleiro.delete_();
					player.delete_();
				}
				else if (lint == 'g' || lint == 'G') {
					player.Guardar_pontuacao();
					//funçao para guardar jogo
					tabuleiro.delete_();
					player.delete_();
					//perguntar se quer sair
					if (lint == 'y' || lint == 'Y') {
						sair = 1;
					}
				}
			}
		}
	}
}

Jogo::~Jogo()
{
}