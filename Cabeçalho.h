#define BIBLIOTECA_H

struct Jogador {
    char nome[50];
    int pontos;
};

// Função para imprimir o tabuleiro
void tabuleiro(char [3][3]);

// Função para verificar se o jogador venceu
bool checarVencedor(char [3][3], char);

// Função para verificar se o jogo está empatado
bool checarEmpate(char [3][3]);

// Função para zerar todo o tabuleiro
void resetarTabuleiro(char [3][3]);

// Função para ordenar de forma crescente o vetor
Jogador ordenaVetor(Jogador*, int);
