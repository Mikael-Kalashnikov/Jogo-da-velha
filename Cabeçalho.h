#define BIBLIOTECA_H

struct Jogador {
    char nome[50];
    int pontos;
};

// Exibe o menu na tela
void exibeMenu();

// Exibe as informa��es que foram passadas do arquivo para o vetor de ponteiro
void ranking(Jogador*, int);

// Exibe as op��es de rodads na tela
void exibeRodadas();

void exibeNivel();

// Fun��o para imprimir o tabuleiro
void tabuleiro(char** , int, int);

// Fun��o para verificar se o jogador venceu
bool checarVencedor(char**, int, int , char);

// Fun��o para verificar se o jogo est� empatado
bool checarEmpate (char**, int, int );

// Fun��o para zerar todo o tabuleiro
void resetarTabuleiro(char**, int, int);

// Exibe o resultado do jogo atual
void resultado(Jogador*);

// Adiciona os jogadores do jogo atual para o vetor
Jogador adicionarJogadores(Jogador*, Jogador*, int);

// Fun��o para ordenar de forma crescente o vetor
Jogador ordenaVetor(Jogador*, int);
