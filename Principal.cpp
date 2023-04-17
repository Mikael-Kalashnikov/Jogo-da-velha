#include <iostream>
#include <string.h>
using namespace std;

struct jogadores {
	string player;
	int total_points;
};

int main() {

	int rounds, difficulty;

	jogadores* novo_Jogador = new jogadores[2];

	cout << "-----JOGO DA VELHA-----\n\n";

	cout << "Informe o nome do jogador 1: ";
	cin >> novo_Jogador[0].player;
	cout << "Informe o nome do jogador 2: ";
	cin >> novo_Jogador[1].player;

	do {
		cout << "\nEscolha a quantidade de rodadas que deseja ser jogadas:\n"
			<< "[1] rodada - [3] rodadas - [5] rodadas - [7] rodadas - [9] rodadas\n";
		cin >> rounds;


		if (rounds % 2 == 0 || rounds > 9 || rounds < 1) {
			cout << "Opcao invalida! Escolha uma das opcoes acima.\n";
		}


	} while (rounds % 2 == 0 || rounds > 9 || rounds < 1);

	int** punctuation_round = new int*[2];
	for (int i = 0; i < 2; i++) {
		punctuation_round[i] = new int[rounds];
	}

	int sum_punctuation[2] = { 0, 0 };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < rounds; j++) {
			if (i == 1) {
				punctuation_round[0][j] = 1;
			}
			else {
				punctuation_round[1][j] = 2;
			}
		}
	}

	do {
		cout << "\nEscolha a dificuldade do jogo:\n"
			<< "[1] Modo 3X3 - Facil\t[2] Modo 4x4 - Medio\t[3] Modo 5x5 - Dificil\n";
		cin >> difficulty;

		if (difficulty < 1 || difficulty>3) {
			cout << "Opcao invalida! Escolha uma das opcoes acima.\n";
		}
	} while (difficulty < 1 || difficulty>3);

	cout << "\nCARREGANDO JOGO...\n";
	if (rounds == 1) {
		cout << "\nO jogo tera " << rounds << " rodada\n";
	}
	else {
		cout << "\nO jogo tera " << rounds << " rodadas\n";
	}
	cout << "\nDificuldade da partida ";
	switch (difficulty)
	{
	case 1:
		cout << "Facil 3x3\n";
		break;
	case 2:
		cout << "Medio 4x4\n";
		break;
	case 3:
		cout << " Dificil 5x5\n";
		break;
	}
	cout << "\nO jogador " << novo_Jogador[0].player << " inicia a partida com X\n"
		<< "O jogador " << novo_Jogador[1].player << " joga em seguida com O\n"
		<< "\nINICIANDO JOGO...\n";
	switch (difficulty)
	{
	case 1:
		cout << "\t3X3:\n";
		for (int i = 0; i < rounds; i++) {
			cout << "\tRodada " << i + 1 << endl
				<< "\t\t__|__|__\n"
				<< "\t\t__|__|__\n"
				<< "\t\t  |  |  \n";
		}
		break;

	case 2:
		cout << "\t4X4:\n";
		for (int i = 0; i < rounds; i++) {
			cout << "\tRodada " << i + 1 << endl
				<< "\t\t__|__|__|__\n"
				<< "\t\t__|__|__|__\n"
				<< "\t\t__|__|__|__\n"
				<< "\t\t  |  |  |  \n";
		}
		break;

	case 3:
		cout << "\t5X5:\n";
		for (int i = 0; i < rounds; i++) {
			cout << "\tRodada " << i + 1 << endl
				<< "\t\t__|__|__|__|__\n"
				<< "\t\t__|__|__|__|__\n"
				<< "\t\t__|__|__|__|__\n"
				<< "\t\t__|__|__|__|__\n"
				<< "\t\t  |  |  |  |  \n";
		}
		break;
	}
}