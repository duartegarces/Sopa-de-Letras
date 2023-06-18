#include <string>
#include <time.h>
#include <iostream>
#include <Windows.h>
#include "tabuleiro.h"
#include "jogador.h"
#include "Jogo.h"
#include "apoiografico.h"

using namespace std;

void fullscreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

int main()
{
	int theme;
	Jogo Game;
	char sair = 'n', new_player;
	char lins;
	srand((int)time(NULL));
	setlocale(LC_ALL, "");
	fullscreen();
	showRectAt(39, 20, 80, 6);
	gotoxy(70, 21);
	cout << "=================" << endl;
	gotoxy(74, 22);
	cout << "Soup Game" << endl;
	gotoxy(70, 23);
	cout << "=================" << endl;
	gotoxy(50, 25);
	cout << "Made by: Pedro Guerra (al70596) e Duarte Garcês (al70860)" << endl;
	Sleep(3000);
	system("cls");
	while (sair != 'y' && sair != 'Y') {
		showRectAt(39, 20, 80, 6);
		gotoxy(55, 21);
		cout << "Escolha uma das opções" << endl;
		gotoxy(55, 22);
		cout << "A.Jogar uma partida" << endl;
		gotoxy(55, 23);
		cout << "B.Carregar uma partida a partir de um ficheiro" << endl;
		gotoxy(55, 24);
		cout << "C.Regras do jogo" << endl;
		gotoxy(55, 25);
		cout << "D.Sair" << endl;
		showRectAt(108, 22, 4, 2);
		gotoxy(110, 23);
		cin >> lins;
		switch (lins) {
		case 'A':
		case 'a':
			system("cls");
			cout << "Introduza um tema:" << endl;
			//cout << mostrar temas
			cin >> theme;
			cout << "Deseja carregar um perfil? Se escolher não irá criar um novo perfil." << endl;
			cin >> new_player;
			if (new_player == 'y' || new_player == 'Y'){
				Game.executar(theme, 0, 0);
			}
			Game.executar(theme, 1, 0);
			break;
		case 'B':
		case 'b':
			//carregar jogo
			break;
		case 'C':
		case 'c':
			system("cls");
			cout << "\n\n\n\n\n\n|||Olá, sê bem-vindo à Sopa de Letras!|||";
			cout << "\n\n-A sopa de letras é um jogo individual, isso significa que apenas 1 jogador pode estar no controlo.\nNeste jogo, o jogador tem como objetivo encontrar todas as palavras da Sopa, estejam elas na diagonal, vertical, horizontal ou invertidas(da direita para a esquerda).\n";
			cout << "-O jogador começa por escolher um tema de palavras para que as possa procurar na própria sopa;\nPosteriormente este deve selecionar a palavra que encontrou e responder no respetivo local de resposta para que possa descobrir se está ou não correto e lhe ser\natribuído uma pontuação em função da quantidade de palavras encontradas e o tempo utilizado para completar o jogo!";
			cout << "\n-No entanto o jogador não tem acesso à lista de palavras contidas na Sopa ao contrário daquilo que por vezes acontece na realidade em revistas de passatempo\nou em jornais diários, para aumentar a dificuldade daquilo que é o jogo.";
			cout << "\n\n\n";
			cout << "\nObrigado por jogarem o nosso jogo, happy games!!!";
			cout << "\n\n\n";
			break;
		case 'D':
		case 'd':
			system("cls");
			showRectAt(39, 20, 80, 6);
			gotoxy(55, 23);
			cout << "Deseja mesmo sair?(y/n):" << endl;
			showRectAt(108, 22, 4, 2);
			gotoxy(110, 23);
			cin >> sair;
			break;
		default:
			break;
		}
	}
	exit(0);
}