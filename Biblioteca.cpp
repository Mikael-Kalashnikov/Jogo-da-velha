#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Cabeçalho.h"
using namespace std;

// Exibe as informações que foram passadas do arquivo para o vetor de ponteiro
void ranking(Jogador* jogadores, int cont) {
    cout << "-----Ranking-----\n"
        << "Nome\tPontuacao\n";
    for (int i = 0; i < cont - 1; i++) {
        cout << jogadores[i].nome << "\t" << jogadores[i].pontos << endl;
    }
    cout << "-----------------\n";
}

// Função para imprimir o tabuleiro
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
// Função para verificar se o jogador venceu
bool checarVencedor(char board[3][3], char player) {
    // Verificação das linhas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    // Verificação das colunas
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }
    // Verificação das diagonais
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Função para verificar se o jogo está empatado
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
    // Preenche o tabuleiro com espaços em branco
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Exibe o resultado do jogo atual
void resultado(Jogador* jogadores) {
    cout << "Nome\t-\tPontuacao\n";
    if (jogadores[0].pontos == jogadores[1].pontos) {
        cout << jogadores[0].nome << "\t-\t" << jogadores[0].pontos << " pontos" << endl;
        cout << jogadores[1].nome << "\t-\t" << jogadores[1].pontos << " pontos" << endl;
    }
    else {
        if (jogadores[0].pontos > jogadores[1].pontos) {
            cout << jogadores[0].nome << "\t-\t" << jogadores[0].pontos << " pontos\t*Vencedor*" << endl;
            cout << jogadores[1].nome << "\t-\t" << jogadores[1].pontos << " pontos" << endl;
        }
        else {
            cout << jogadores[1].nome << "\t-\t" << jogadores[1].pontos << " pontos\t*Vencedor*" << endl;
            cout << jogadores[0].nome << "\t-\t" << jogadores[0].pontos << " pontos" << endl;
        }
    }
}

// Adiciona os jogadores do jogo atual para o vetor
Jogador adicionarJogadores(Jogador* jogadoresArquivo, Jogador* jogadores, int cont) {
    strcpy(jogadoresArquivo[cont - 1].nome, jogadores[0].nome);
    jogadoresArquivo[cont - 1].pontos = jogadores[0].pontos;

    strcpy(jogadoresArquivo[cont].nome, jogadores[1].nome);
    jogadoresArquivo[cont].pontos = jogadores[1].pontos;

    return *jogadoresArquivo;
}

// Função que ordena o vetor de modo crescente
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