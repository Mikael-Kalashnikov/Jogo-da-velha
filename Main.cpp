#include <iostream>
#include <fstream>
#include <string>
#include "Cabe�alho.h"
using namespace std;

struct Jogador {
    string nome;
    int pontos;
};

int main() {
    char tab[3][3]; // Tabuleiro do jogo
    char jogadorAtual = 'X'; // Jogador atual
    int linha, coluna; // Posi��o escolhida pelo jogador
    bool fimdeJogo = false; // Vari�vel de controle do fim do jogo
    string vencedor = ""; // Nome do jogador vencedor
    int numRodadas; // N�mero de rodadas
    int cont = 0;

    ifstream fin;

    // Abre arquivo para leitura de texto
    fin.open("Ranking.txt");
    if (!fin.is_open()) {
        cout << "A abertura do arquivo falhou!" << endl;
        exit(EXIT_FAILURE);
    }

    // Conta a quantidade de linhas preenchidas existentes no arquivo
    string line;
    while (getline(fin, line)) {
        cont++;
    }
    // Arquivo � fechado, pois chegou ao seu fim
    fin.close();

    // Aberto o arquivo para que seja realizado a leitura dos dados
    fin.open("Ranking.txt");
    char name[100];
    fin.getline(name, 100);

    // Vetor din�mico que armazena as informa��es do arquivo
    Jogador* jogadoresArquivo = new Jogador[cont+1];

    for (int i = 0; i < cont; i++) {
        fin >> jogadoresArquivo[i].nome;
        fin >> jogadoresArquivo[i].pontos;
    }
    // Finalizado a leitura do arquivo
    fin.close();

    // Exibe as informa��es que foram passadas do arquivo para o vetor de ponteiro
    cout << "---Ranking---\n"
        << "Nome\tPontuacao\n";
    for (int i = 0; i < cont-1; i++) {
        cout << jogadoresArquivo[i].nome << "\t" << jogadoresArquivo[i].pontos << endl;
    }
    
    // Vetor din�mico que armazena as informa��es dos jogadores
    Jogador* jogadores = new Jogador[2];
    
    cout << "\nDigite o nome do Jogador 1 (X): ";
    cin >> jogadores[0].nome;
    cout << "Digite o nome do Jogador 2 (O): ";
    cin >> jogadores[1].nome;

    // Solicita a quantidade de rodadas a serem jogadas
    do {
        cout << "\nInforme a quantidade de rodadas a serem jogadas"
            << "\n[1] rodada - [3] rodadas - [5] rodadas - [7] rodadas - [9] rodadas:\n";
        cin >> numRodadas;
    } while (numRodadas != 1 && numRodadas != 3 && numRodadas != 5 && numRodadas != 7 && numRodadas != 9);

    // Criado uma matriz 2 por n+1 para armazenar a pontua��o de cada rodada
    int** pontuacao = new int* [2];
    // A ultima posi��o � destinada a soma das anteriores
    for (int i = 0; i < 2; i++) {
        pontuacao[i] = new int[numRodadas + 1];
    }

    // Inicializa toda a matriz de pontua��o zerada
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < numRodadas + 1; j++) {
            pontuacao[i][j] = 0;
        }
    }
    // Inicializa o tabuleiro com espa�os vazios
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

            // Verifica se a posi��o escolhida pelo jogador � v�lida
            if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tab[linha - 1][coluna - 1] != ' ') {
                cout << "Posicao invalida. Tente novamente." << endl;
                continue;
            }

            // Marca a posi��o escolhida com o s�mbolo do jogador atual
            tab[linha - 1][coluna - 1] = jogadorAtual;

            // Verifica se o jogador venceu
            if (checarVencedor(tab, jogadorAtual)) {
                fimdeJogo = true;
                vencedor = (jogadorAtual == 'X') ? jogadores[0].nome : jogadores[1].nome;
                vencedor = (jogadorAtual == 'X') ? pontuacao[0][round - 1] += 2 : pontuacao[1][round - 1] += 2;
            }
            else {
                // Verifica se o jogo est� empatado
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
                // Reinicia o jogo para a pr�xima rodada
                resetarTabuleiro(tab);
                jogadorAtual = 'X';
                fimdeJogo = false;
                vencedor = "";
            }
        }
            // Soma de todas as rodadas guardada na �ltima posi��o da matriz 
            for (int j = 0; j < numRodadas; j++) {
                pontuacao[0][numRodadas] += pontuacao[0][j];
            }
            for (int k = 0; k < numRodadas; k++) {
                pontuacao[1][numRodadas] += pontuacao[1][k];
            }
    // A soma total dos pontos � atribuida ao registro de seu respectivo jogador
    jogadores[0].pontos = pontuacao[0][numRodadas];
    jogadores[1].pontos = pontuacao[1][numRodadas];

    // Exibe a coloca��o de cada jogador, seu nome e sua pontua��o em ordem descrescente
    cout << "Colocacao\tNome\tPontuacao\n";
    if (jogadores[0].pontos == jogadores[1].pontos) {
        cout << "Vencedor\t" << jogadores[0].nome << "\t" << jogadores[0].pontos << " pontos" << endl;
        cout << "Segundo\t\t" << jogadores[1].nome << "\t" << jogadores[1].pontos << " pontos" << endl;
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

    jogadoresArquivo[cont-1].nome = jogadores[0].nome;
    jogadoresArquivo[cont-1].pontos = jogadores[0].pontos;

    jogadoresArquivo[cont].nome = jogadores[1].nome;
    jogadoresArquivo[cont].pontos = jogadores[1].pontos;
    
    // Abre o arquivo para escrita
    ofstream fout;
    fout.open("Ranking.txt");
    if (!fout.is_open()) {
        cout << "A abertura do arquivo falhou!" << endl;
        exit(EXIT_FAILURE);
    }

    // Escreve no arquivo o nome e a pontua��o do jogador
    fout << "Nome\t\tPontua��o\n";

    for (int p = 0; p < cont+1; p++) {
    fout << jogadoresArquivo[p].nome << "\t\t" << jogadoresArquivo[p].pontos << endl;
    }
    fout.close();

    // Libera mem�ria do vetor e da matriz de ponteiro
    delete[] pontuacao;
    delete[] jogadores;
    delete[] jogadoresArquivo;
}