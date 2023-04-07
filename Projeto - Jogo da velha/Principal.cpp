#include <iostream>
using namespace std;

int rounds, difficulty;

struct jogadores {
	string player;
	int* total_points = new int[rounds+1];
};

void qtd_rounds();

void level_difficulty();

void display_difficulty(int);

void display_game(int, int);

void result(jogadores);

int main() {

	jogadores* jogador = new jogadores[2];

	cout << "-----JOGO DA VELHA-----\n\n";

	cout << "Informe o nome do jogador 1: ";
	cin >> jogador->player[0];
	cout << "Informe o nome do jogador 2: ";
	cin >> jogador->player[1];

	qtd_rounds;

	level_difficulty;
	
	cout << "\nCARREGANDO JOGO...\n";
		if (rounds == 1) {
			cout << "\nO jogo tera " << rounds << " rodada\n";
		}
		else {
			cout << "\nO jogo tera " << rounds << " rodadas\n";
		}
		
		display_difficulty(difficulty);

		cout << "\nO jogador " << jogador->player[0] << " inicia a partida com X\n"
		<< "O jogador " << jogador->player[1] << " joga em seguida com O\n"
			<< "\nINICIANDO JOGO...\n";

		display_game(difficulty, rounds);

		result(*jogador);
}

void qtd_rounds() {

	do {
		cout << "\nEscolha a quantidade de rodadas que deseja ser jogadas:\n"
			<< "[1] rodada - [3] rodadas - [5] rodadas - [7] rodadas - [9] rodadas\n";
		cin >> rounds;

		int* total_points = new int[rounds];

		if (rounds % 2 == 0 || rounds > 9 || rounds < 1) {
			cout << "Opcao invalida! Escolha uma das opcoes acima.\n";
		}

	} while (rounds % 2 == 0 || rounds > 9 || rounds < 1);

}

void level_difficulty() {

	do {
		cout << "\nEscolha a dificuldade do jogo:\n"
			<< "[1] Modo 3X3 - Facil\t[2] Modo 4x4 - Medio\t[3] Modo 5x5 - Dificil\n";
		cin >> difficulty;

		if (difficulty < 1 || difficulty>3) {
			cout << "Opcao invalida! Escolha uma das opcoes acima.\n";
		}
	} while (difficulty < 1 || difficulty>3);

}

void display_difficulty(int difficulty) {

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

}

void display_game(int difficulty, int rounds) {

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

void result(jogadores *jogador) {

	cout << "Resultado:\n";

	if (jogador[0].total_points[rounds + 1] > jogador[1].total_points[rounds + 1]) {
		cout << "Vencedor: " << jogador->player[0] << endl
			<< "Pontuacao: " << jogador[0].total_points[rounds + 1] << endl;

		cout << endl << jogador->player[1]
			<< "\nPontuacao: " << jogador[1].total_points[rounds + 1] << endl;
	}
	else {
		cout << "Vencedor: " << jogador->player[1] << endl
			<< "Pontuacao: " << jogador[1].total_points[rounds + 1] << endl;

		cout << endl << jogador->player[0]
			<< "\nPontuacao: " << jogador[0].total_points[rounds + 1] << endl;
	}
}