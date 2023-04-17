#include <iostream>
#include "Cabeçalho.h"
using namespace std;

struct Jogador {
    string nome;
    int pontos;
};

int main() {
    char tab[3][3]; // Tabuleiro do jogo
    char jogadorAtual = 'X'; // Jogador atual
    int linha, coluna; // Posição escolhida pelo jogador
    bool fimdeJogo = false; // Variável de controle do fim do jogo
    string vencedor = ""; // Nome do jogador vencedor
    int numRodadas; // Número de rodadas

    Jogador* jogadores = new Jogador[2];

    cout << "Digite o nome do Jogador 1 (X): ";
    cin >> jogadores[0].nome;
    cout << "Digite o nome do Jogador 2 (O): ";
    cin >> jogadores[1].nome;

    // Solicita a quantidade de rodadas
    do {
        cout << "\nInforme a quantidade de rodadas a serem jogadas"
            << "\n[1] rodada - [3] rodadas - [5] rodadas - [7] rodadas - [9] rodadas:\n";
        cin >> numRodadas;
    } while (numRodadas != 1 && numRodadas != 3 && numRodadas != 5 && numRodadas != 7 && numRodadas != 9);

    int** pontuacao = new int* [2];

    for (int i = 0; i < 2; i++) {
        pontuacao[i] = new int[numRodadas + 1];
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < numRodadas + 1; j++) {
            pontuacao[i][j] = 0;
        }
    }
    // Inicializa o tabuleiro com espaços vazios
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tab[i][j] = ' ';
        }
    }

    cout << "\nBem-vindo ao Jogo da Velha!\n" << endl;
    cout << jogadores[0].nome << "(X) e "
         << jogadores[1].nome << "(O)\n" << endl;

    // Loop principal do jogo
    for (int round = 1; round <= numRodadas; round++) {
        while (!fimdeJogo) {
            cout << "\nRodada " << round << "\n" << endl;
            tabuleiro(tab);
            if (jogadorAtual == 'X') {
                cout << "\nVez do jogador " << jogadores[0].nome;
            }
            else {
                cout << "\nVez do jogador " << jogadores[1].nome;
            }
            cout << "\nDigite a linha (1, 2 ou 3): ";
            cin >> linha;
            cout << "Digite a coluna (1, 2 ou 3): ";
            cin >> coluna;

            // Verifica se a posição escolhida pelo jogador é válida
            if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tab[linha - 1][coluna - 1] != ' ') {
                cout << "Posicao invalida. Tente novamente." << endl;
                continue;
            }

            // Marca a posição escolhida com o símbolo do jogador atual
            tab[linha - 1][coluna - 1] = jogadorAtual;

            // Verifica se o jogador venceu
            if (checarVencedor(tab, jogadorAtual)) {
                fimdeJogo = true;
                vencedor = (jogadorAtual == 'X') ? jogadores[0].nome : jogadores[1].nome;
            }

            // Verifica se o jogo está empatado
            if (checarEmpate(tab)) {
                fimdeJogo = true;
                vencedor = "Empate";
            }

            // Alterna o jogador atual
            if (jogadorAtual == 'X')
                jogadorAtual = 'O';
            else
                jogadorAtual = 'X';
        }

        if (fimdeJogo) {
            // Exibe o nome do jogador vencedor ou empate
            cout << "\nFim do jogo!\n" << endl;
            tabuleiro(tab);

            if (vencedor == "Empate") {
                cout << "\nJogo empatado!\n" << endl;
            }
            else {
                cout << "\nJogador vencedor da rodada " << round << ": " << vencedor << "\n" << endl;
            }
            // Reinicia o jogo para a próxima rodada
            resetarTabuleiro(tab);
            jogadorAtual = 'X';
            fimdeJogo = false;
            vencedor = "";
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= numRodadas; j++) {
                pontuacao[i][numRodadas] += pontuacao[i][j];
            }
        }
    }
    cout << jogadores[0].nome << ": " << pontuacao[0][numRodadas] << " pontos" << endl;
    cout << jogadores[1].nome << ": " << pontuacao[1][numRodadas] << " pontos" << endl;
    delete[] jogadores;
}