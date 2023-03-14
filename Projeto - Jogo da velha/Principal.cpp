#include <iostream>
using namespace std;

int main() {

	char player1[20], player2[20];
	//pontos totais deve ser um vetor que armazene a pontuação de cada rodada, a ultima posição dever ser a soma das outras posições
	int total_points1 = 2, total_points2 = 0;
	int rounds, difficulty;

	cout << "-----JOGO DA VELHA-----\n\n";

	cout << "Informe o nome do jogador 1: ";
	cin >> player1;
	cout << "Informe o nome do jogador 2: ";
	cin >> player2;

	do {
		cout << "\nEscolha a quantidade de rodadas que deseja ser jogadas:\n"
			<< "[1] rodada - [3] rodadas - [5] rodadas - [7] rodadas - [9] rodadas\n";
		cin >> rounds;

		if (rounds % 2 == 0 || rounds > 9 || rounds < 1) {
			cout << "Opcao invalida! Escolha uma das opcoes acima.\n";
		}

	} while (rounds % 2 == 0 || rounds > 9 || rounds < 1);

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
		cout << "\nO jogador " << player1 << " inicia a partida com X\n"
		<< "O jogador " << player2 << " joga em seguida com O\n"
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
		cout << "Resultado:\n";

		if (total_points1 > total_points2) {
			cout << "Vencedor: " << player1 << endl
				<< "Pontuacao: " << total_points1 << endl;

			cout << endl << player2
				<< "\nPontuacao: " << total_points2 << endl;
		}
		else {
			cout << "Vencedor: " << player2 << endl
				<< "Pontuacao: " << total_points2 << endl;

			cout << endl << player1
				<< "\nPontuacao: " << total_points1 << endl;
		}
}