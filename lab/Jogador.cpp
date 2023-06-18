#include "jogador.h"
#include <string>
#include <iostream>
//#include <Windows.h>
#include <fstream>

using namespace std;

jogador::jogador()
{
	nome = "";
	idade = 0;
	pontuação = 0;
	id = 0;
}

void jogador::Set_nome()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Introduz o teu nome:" << endl;
	getline(cin, nome);
	cout << "Qual a tua idade?" << endl;
	cin >> idade;
	if (idade < 18) {
		cout << "Desculpa mas este jogo é para maiores de 18 anos. Volta daqui a " << (18 - idade) << " anos." << endl;
		exit(1);
	}
	pontuação = 1;
	Set_id();
}

void jogador::Set_id()
{
	ifstream is;
	string aux;
	int i = 0;
	is.open("pontuacao.txt");
	if (!is) {
		cout << "Erro, ficheiro";
		exit(1);
	}
	while (!is.eof()) {
		getline(is, aux);
		if (!aux.empty()) {
			i++;
		}
	}
	if (i == 0) {
		id = 1;
	}
	else
		id = i + 1;
}

void jogador::view_stats()
{
	cout << nome << endl;
	cout << pontuação << endl;
}

string jogador::play()
{
	string palavra;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Palavra encontrada:" << endl;
	getline(cin, palavra);
	return palavra;
}

void jogador::Guardar_pontuacao()
{
	ifstream is;
	ofstream os;
	string* info;
	string aux;
	int i = 0, j = 0;
	is.open("pontuacao.txt");
	if (!is) {
		cout << "Erro, ficheiro";
		exit(1);
	}
	while (!is.eof()) {
		getline(is, aux);
		if (!aux.empty()) {
			i++;
		}
	}
	is.close();
	if (i == 0) {
		os.open("pontuacao.txt");
		if (!os) {
			cout << "Erro, ficheiro";
			exit(1);
		}
		os << id << "#" << nome << "#" << idade << "#" << pontuação << endl;
		os.close();
	}
	else {
		info = new string[i+1];
		is.open("pontuacao.txt");
		if (!is) {
			cout << "Erro, ficheiro";
			exit(1);
		}
		while (!is.eof()) {
				getline(is, info[j]);
				j++;
		}
		is.close();
		os.open("pontuacao.txt");
		if (!os) {
			cout << "Erro, ficheiro";
			exit(1);
		}
		info[i] = to_string(id) + "#"+ nome + "#" + to_string(idade) + "#" + to_string(pontuação);
		for (j = 0; j < (i+1); j++) {
			os << info[j] << endl;
		}
		delete[] info;
		os.close();
	}
}

void jogador::delete_()
{
	pontuação = 0;
}

jogador::~jogador()
{
}