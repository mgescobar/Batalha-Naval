//Definições
#ifndef _funcoes_h
#define _funcoes_h

#define porta_aviao 'P'
#define navio_tanque 'N'
#define contratorpedeiro 'C'
#define submarino 'S'

// Includes necessários.
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Alloca o espaço de memória que será utilizado retornando como uma matriz.
char** AllocaTabuleiro(int larg, int alt);

// Libera a memória utilizada na preparação do tabuleiro(matriz).
void LiberaMemoria(char **tab1, char **tab2, char **tab3, char **tab4, int alt);

// Realiza a impressão do tabuleiro na tela.
void imprime(char **tab, int lin, int col, int nrTab);

// "Zera" o tabuleiro para valores padrão.
void ZeraTabuleiro(char **tab, int larg, int alt);

// Contabiliza o tempo desde o início do jogo e printa na tela.
void Tempo(time_t tempo_inicio, time_t tempo_final);

// Realiza e retorna um número sorteado atráves da seed do tempo.
int FazSorteio(int n);

// Recebe e armazena a largura do tabuleiro informada pelo usuário.
int recebeLarg();

// Recebe e armazena a altura do tabuleiro informada pelo usuário.
int recebeAlt();

// Verifica se o barco pode ser inserido na horizontal e retorna em qual 
// posição ele pode, sorteando uma delas caso seja possível nas duas.
int VerificadorH(char **tab, int lin, int col, int n, int larg);

// Verifica se o barco pode ser inserido na vertical e retorna em qual 
// posição ele pode, sorteando uma delas caso seja possível nas duas.
int VerificadorV(char **tab, int lin, int col, int n, int alt);

// Insere o barco em posição aleatória com o auxilio do verificador.
void SortNav(char **tab, int larg, int alt, int qtd_nav, char navio,int tamNav);

// Realiza a inserção do número de barcos informados pelo usuário.
void SorteiaNavios(char **tab, int larg, int alt, int nav_tanq, int submar, 
      int contratorp, int porta_av);

// Realiza a jogada e retorna a vida do jogador oponente.
int FazJogada(char **real, char **aux, int coluna, int linha,
      int vida, int larg, int alt);

// Realiza a jogada do computador e retorna a vida do jogador humano.
int JogadaIA(char **tab, char **aux, int larg, int alt, int col, int lin, int vida);

// Checa se o jogou acabou fazendo uma comparação entre as vidas restantes,
// retornando true para dizer que acabou.
bool checkaFinal(int vida1, int vida2);

// Inicia o jogo em si no modo normal (player vs player), chamando todas
// as funções necessárias.
void Normal(char **tab1, char** aux1, char **tab2, char **aux2,
      int nav_tanq, int submar, int contratorp, int porta_av, int alt,int larg);

// Inicia o jogo em si no modo Inteligência Artificial (player vs máquina), 
// chamando todas as funções necessárias.
void IntArt(char **tab1, char** aux1, char **tab2, char **aux2,
      int nav_tanq, int submar, int contratorp, int porta_av, int alt,int larg);

#endif