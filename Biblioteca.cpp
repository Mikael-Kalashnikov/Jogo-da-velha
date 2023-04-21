#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Cabe�alho.h"
using namespace std;

// Fun��o para imprimir o tabuleiro
void tabuleiro(char board[3][3]) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
// Fun��o para verificar se o jogador venceu
bool checarVencedor(char board[3][3], char player) {
    // Verifica��o das linhas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    // Verifica��o das colunas
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }
    // Verifica��o das diagonais
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Fun��o para verificar se o jogo est� empatado
bool checarEmpate(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void resetarTabuleiro(char board[3][3]) {
    // Preenche o tabuleiro com espa�os em branco
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Fun��o que ordena o vetor de modo crescente
Jogador ordenaVetor(Jogador* vetor, int tamanho) {
    for (int i = 0; i < tamanho + 1; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (vetor[j].pontos < vetor[j + 1].pontos) {
                int temp = vetor[j].pontos;
                char temName[50];
                strcpy(temName, vetor[j].nome);

                vetor[j].pontos = vetor[j + 1].pontos;
                strcpy(vetor[j].nome, vetor[j + 1].nome);

                vetor[j + 1].pontos = temp;
                strcpy(vetor[j + 1].nome, temName);
            }
        }
    }
    return *vetor;
}
