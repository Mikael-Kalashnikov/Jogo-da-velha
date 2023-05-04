#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Cabeçalho.h"
using namespace std;

int main() {
    char jogadorAtual = 'X'; // Jogador atual
    int linha, coluna; // Posição escolhida pelo jogador
    bool fimdeJogo = false; // Variável de controle do fim do jogo
    string vencedor = ""; // Nome do jogador vencedor
    string arquivo;
    int numRodadas, nivel; // Número de rodadas
    int lin, col;
    int opc;

    do {
        cout << "\n------MENU------\n"
            << "[1] Novo jogo\n"
            << "[2] Ranking 3x3\n"
            << "[3] Ranking 4x4\n"
            << "[4] Ranking 5x5\n"
            << "[5] Sair\n"
            << "----------------\n";
        cin >> opc;

        if (opc < 1 || opc > 5) {
            cout << "Opcao invalida. Tente novamente\n\n";
        }

        if (opc == 1) {
            // Vetor dinâmico que armazena as informações dos jogadores
            Jogador* jogadores = new Jogador[2];

            // Preciso limpar buffer, pois fica armazenado o valor de opc
            cin.ignore(100, '\n');

            cout << "\nDigite o nome do Jogador 1 (X): ";
            cin.getline(jogadores[0].nome, 50);
            cout << "Digite o nome do Jogador 2 (O): ";
            cin.getline(jogadores[1].nome, 50);

            // Solicita a quantidade de rodadas a serem jogadas
            do {
                cout << "\nInforme a quantidade de rodadas a serem jogadas"
                    << "\n[1] rodada\n"
                    << "[3] rodadas\n"
                    << "[5] rodadas\n"
                    << "[7] rodadas\n"
                    << "[9] rodadas\n";
                cin >> numRodadas;
                if (numRodadas != 1 && numRodadas != 3 && numRodadas != 5 && numRodadas != 7 && numRodadas != 9) {
                    cout << "\nOpcao invalida. Tente novamente\n";
                }
            } while (numRodadas != 1 && numRodadas != 3 && numRodadas != 5 && numRodadas != 7 && numRodadas != 9);

            do {
                cout << "\nInforme o nivel do jogo"
                    << "\n[1] Tabuleiro 3x3\n"
                    << "[2] Tabuleiro 4x4\n"
                    << "[3] Tabuleiro 5x5\n";
                cin >> nivel;
                if (nivel != 1 && nivel != 2 && nivel != 3) {
                    cout << "\nOpcao invalida. Tente novamente\n";
                }
            } while (nivel != 1 && nivel != 2 && nivel != 3);

            if (nivel == 1) {
                arquivo = "Ranking3x3.txt";
                lin = 3;
                col = 3;
            }
            if (nivel == 2) {
                arquivo = "Ranking4x4.txt";
                lin = 4;
                col = 4;
            }
            if (nivel == 3) {
                arquivo = "Ranking5x5.txt";
                lin = 5;
                col = 5;
            }

            ifstream finn;

            // Abre arquivo para leitura de texto
            finn.open(arquivo);

            // Verifica se teve alguma falha ao abrir o arquivo
            if (!finn.is_open()) {
                cout << "A abertura do arquivo falhou!" << endl;
                exit(EXIT_FAILURE);
            }

            // Conta a quantidade de linhas preenchidas existentes no arquivo
            string line;
            int cont = 0;
            while (getline(finn, line)) {
                cont++;
            }
            // Arquivo é fechado, pois chegou ao seu fim
            finn.close();

            // Aberto o arquivo para que seja realizado a leitura dos dados
            finn.open(arquivo);
            char name[50];
            finn.getline(name, 50);

            // Vetor dinâmico que armazena as informações do arquivo
            Jogador* jogadoresArquivo = new Jogador[cont + 1];

            for (int i = 0; i < cont; i++) {
                finn >> jogadoresArquivo[i].nome;
                finn >> jogadoresArquivo[i].pontos;
            }
            // Finalizado a leitura do arquivo
            finn.close();

            // Tabuleiro do jogo
            char** tabu = new char* [lin];
            for (int i = 0; i < lin; i++) {
                tabu[i] = new char[col];
            }

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
            for (int i = 0; i < lin; i++) {
                for (int j = 0; j < col; j++) {
                    tabu[i][j] = ' ';
                }
            }

            cout << "\n---------------------------"
                << "\nBem-vindo ao Jogo da Velha!\n"
                << "---------------------------\n\n";

            cout << jogadores[0].nome << " joga com (X) e "
                << jogadores[1].nome << " joga com (O)" << endl;

            // Loop principal do jogo
            for (int round = 1; round <= numRodadas; round++) {
                while (!fimdeJogo) {
                    cout << "\n--------"
                        << "\nRodada " << round << "\n"
                        << "--------\n";

                    tabuleiro(tabu, lin, col);
                    if (jogadorAtual == 'X') {
                        cout << "\nVez do jogador(a) " << jogadores[0].nome << "(" << jogadorAtual << ")" << endl;
                    }
                    else {
                        cout << "\nVez do jogador(a) " << jogadores[1].nome << "(" << jogadorAtual << ")" << endl;
                    }
                    cout << "\nDigite a linha (1, 2 ou 3): ";
                    cin >> linha;
                    cout << "Digite a coluna (1, 2 ou 3): ";
                    cin >> coluna;

                    // Verifica se a posição escolhida pelo jogador é válida
                    if (linha < 1 || linha > lin || coluna < 1 || coluna > col || tabu[linha - 1][coluna - 1] != ' ') {
                        cout << "Posicao invalida. Tente novamente." << endl;
                        continue;
                    }

                    // Marca a posição escolhida com o símbolo do jogador atual
                    tabu[linha - 1][coluna - 1] = jogadorAtual;

                    // Verifica se o jogador venceu
                    if (checarVencedor(tabu, lin, col, jogadorAtual)) {
                        fimdeJogo = true;
                        vencedor = (jogadorAtual == 'X') ? jogadores[0].nome : jogadores[1].nome;
                        vencedor = (jogadorAtual == 'X') ? pontuacao[0][round - 1] += 2 : pontuacao[1][round - 1] += 2;
                    }
                    else {
                        // Verifica se o jogo está empatado
                        if (checarEmpate(tabu, lin, col)) {
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
                    tabuleiro(tabu, lin, col);

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
                    resetarTabuleiro(tabu, lin, col);
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

            // Exibe o resultado do jogo atual
            resultado(jogadores);

            // Adiciona os jogadores do jogo atual para o vetor
            adicionarJogadores(jogadoresArquivo, jogadores, cont);

            // Chama a função com os elementos já ordenados
            ordenaVetor(jogadoresArquivo, cont);

            // Abre o arquivo para escrita
            ofstream fout;
            fout.open(arquivo);

            // Escreve no arquivo o nome e a pontuação do jogador
            fout << "Nome\t\tPontuacao\n";

            for (int p = 0; p < cont + 1; p++) {
                fout << jogadoresArquivo[p].nome << "\t\t" << jogadoresArquivo[p].pontos << endl;
            }
            fout.close();

            // Libera memória do vetor e da matriz de ponteiro
            delete[] pontuacao;
            delete[] jogadores;
            delete[] jogadoresArquivo;
        }
        if (opc == 2) {
            ifstream fin;

            // Abre arquivo para leitura de texto
            fin.open("Ranking3x3.txt");

            // Verifica se teve alguma falha ao abrir o arquivo
            if (!fin.is_open()) {
                cout << "A abertura do arquivo falhou!" << endl;
                exit(EXIT_FAILURE);
            }

            // Conta a quantidade de linhas preenchidas existentes no arquivo
            string line;
            cout << "-----Ranking 3x3-----\n";
            while (getline(fin, line)) {
                cout << line << endl;
            }
            // Arquivo é fechado, pois chegou ao seu fim
            fin.close();
        }
        if (opc == 3) {
            ifstream fin;

            // Abre arquivo para leitura de texto
            fin.open("Ranking4x4.txt");

            // Verifica se teve alguma falha ao abrir o arquivo
            if (!fin.is_open()) {
                cout << "A abertura do arquivo falhou!" << endl;
                exit(EXIT_FAILURE);
            }

            // Conta a quantidade de linhas preenchidas existentes no arquivo
            string line;
            cout << "-----Ranking 4x4-----\n";
            while (getline(fin, line)) {
                cout << line << endl;
            }
            // Arquivo é fechado, pois chegou ao seu fim
            fin.close();
        }
        if (opc == 4) {
            ifstream fin;

            // Abre arquivo para leitura de texto
            fin.open("Ranking5x5.txt");

            // Verifica se teve alguma falha ao abrir o arquivo
            if (!fin.is_open()) {
                cout << "A abertura do arquivo falhou!" << endl;
                exit(EXIT_FAILURE);
            }

            // Conta a quantidade de linhas preenchidas existentes no arquivo
            string line;
            cout << "-----Ranking 5x5-----\n";
            while (getline(fin, line)) {
                cout << line << endl;
            }
            // Arquivo é fechado, pois chegou ao seu fim
            fin.close();
        }
        if (opc == 5) {
            cout << "\nFinalizando jogo...\n";
            exit(5);
        }
    }while (opc!=5);
}