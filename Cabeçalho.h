#define BIBLIOTECA_H

struct Jogador {
    char nome[50];
    int pontos;
};

// Fun��o para imprimir o tabuleiro
void tabuleiro(char [3][3]);

// Fun��o para verificar se o jogador venceu
bool checarVencedor(char [3][3], char);

// Fun��o para verificar se o jogo est� empatado
bool checarEmpate(char [3][3]);

// Fun��o para zerar todo o tabuleiro
void resetarTabuleiro(char [3][3]);

// Fun��o para ordenar de forma crescente o vetor
Jogador ordenaVetor(Jogador*, int);
