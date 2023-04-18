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

    // Solicita a quantidade de rodadas a serem jogadas
    do {
        cout << "\nInforme a quantidade de rodadas a serem jogadas"
            << "\n[1] rodada - [3] rodadas - [5] rodadas - [7] rodadas - [9] rodadas:\n";
        cin >> numRodadas;
    } while (numRodadas != 1 && numRodadas != 3 && numRodadas != 5 && numRodadas != 7 && numRodadas != 9);

    // Criado uma matriz 2 por n+1 para armazenar a pontuação de cada rodada
    int** pontuacao = new int* [2];
    // A ultima posição é destinada a soma das anteriores
    for (int i = 0; i < 2; i++) {
        pontuacao[i] = new int[numRodadas + 1];
    }

    // Inicializa toda a matriz de pontuação zerada
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
                vencedor = (jogadorAtual == 'X') ? pontuacao[0][round - 1] += 2 : pontuacao[1][round - 1] += 2;
            }
            else {
                // Verifica se o jogo está empatado
                if (checarEmpate(tab)) {
                    fimdeJogo = true;
                    pontuacao[0][round - 1] += 1;
                    pontuacao[1][round - 1] += 1;
                    vencedor = "Empate";
                }
            }

            // Alterna o jogador atual
            if (jogadorAtual == 'X') {
                jogadorAtual = 'O';
            }
            else {
                jogadorAtual = 'X';
            }
        }

        if (fimdeJogo) {
            // Exibe o nome do jogador vencedor ou empate
            cout << "\nFim do jogo!\n" << endl;
            tabuleiro(tab);

            // Exibe o resultado de cada rodada jogada
            if (vencedor == "Empate") {
                cout << "\nJogo empatado!\n" << endl;
            }
            else {
                if (jogadorAtual == 'O') {
                    cout << "\nVencedor da rodada " << round << ": " << jogadores[0].nome << "\n" << endl;
                }
                else {
                    cout << "\nVencedor da rodada " << round << ": " << jogadores[1].nome << "\n" << endl;
                }
            }
                // Reinicia o jogo para a próxima rodada
                resetarTabuleiro(tab);
                jogadorAtual = 'X';
                fimdeJogo = false;
                vencedor = "";
            }
        }
            // Soma de todas as rodadas guardada na última posição da matriz 
            for (int j = 0; j < numRodadas; j++) {
                pontuacao[0][numRodadas] += pontuacao[0][j];
            }
            for (int k = 0; k < numRodadas; k++) {
                pontuacao[1][numRodadas] += pontuacao[1][k];
            }
    // A soma total dos pontos é atribuida ao registro de seu respectivo jogador
    jogadores[0].pontos = pontuacao[0][numRodadas];
    jogadores[1].pontos = pontuacao[1][numRodadas];

    // Exibe a colocação de cada jogador, seu nome e sua pontuação em ordem descrescente
    cout << "Colocacao\tNome\tPontuacao\n";
    if (jogadores[0].pontos == jogadores[1].pontos) {
        cout << "-\t" << jogadores[0].nome << "\t" << jogadores[0].pontos << " pontos" << endl;
        cout << "-\t\t" << jogadores[1].nome << "\t" << jogadores[1].pontos << " pontos" << endl;
    }
    else {
        if (jogadores[0].pontos > jogadores[1].pontos) {
            cout << "Vencedor\t" << jogadores[0].nome << "\t" << jogadores[0].pontos << " pontos" << endl;
            cout << "Segundo\t\t" << jogadores[1].nome << "\t" << jogadores[1].pontos << " pontos" << endl;
        }
        else {
            cout << "Vencedor\t" << jogadores[1].nome << "\t" << jogadores[1].pontos << " pontos" << endl;
            cout << "Segundo\t\t" << jogadores[0].nome << "\t" << jogadores[0].pontos << " pontos" << endl;
        }
    }
    delete[] pontuacao;
    delete[] jogadores;
}