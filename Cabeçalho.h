#define BIBLIOTECA_H

// Função para imprimir o tabuleiro
void tabuleiro(char [3][3]);

// Função para verificar se o jogador venceu
bool checarVencedor(char [3][3], char);

// Função para verificar se o jogo está empatado
bool checarEmpate(char [3][3]);

void resetarTabuleiro(char [3][3]);

