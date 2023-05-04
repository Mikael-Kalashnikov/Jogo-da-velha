#define BIBLIOTECA_H

struct Jogador {
    char nome[50];
    int pontos;
};

void ranking(Jogador*, int);

// Função para imprimir o tabuleiro
void tabuleiro(char** , int, int);

// Função para verificar se o jogador venceu
bool checarVencedor(char**, int, int , char);

// Função para verificar se o jogo está empatado
bool checarEmpate (char**, int, int );

// Função para zerar todo o tabuleiro
void resetarTabuleiro(char**, int, int);

// Exibe o resultado do jogo atual
void resultado(Jogador*);

// Adiciona os jogadores do jogo atual para o vetor
Jogador adicionarJogadores(Jogador*, Jogador*, int);

// Função para ordenar de forma crescente o vetor
Jogador ordenaVetor(Jogador*, int);
