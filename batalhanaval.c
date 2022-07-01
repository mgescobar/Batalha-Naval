#include <stdio.h>
#include "funcoes.h"

int main(void)
{
  srand(time(NULL));

  time_t tempo_inicio, tempo_final;
  int larg = recebeLarg();
  int alt = recebeAlt();
  int navTanq = 0, subm = 0, ctrtorp = 0, portAv = 0;
  int total_nav = 0, modo = -1;

  char **jogador1 = AllocaTabuleiro(larg, alt);
  char **jogador2 = AllocaTabuleiro(larg, alt);
  char **Aux1 = AllocaTabuleiro(larg, alt);
  char **Aux2 = AllocaTabuleiro(larg, alt);
  
  printf("Digite o número desejado de Navios Tanque: ");
  scanf("%d", &navTanq);
  printf("Digite o número desejado de Submarinos: ");
  scanf("%d", &subm);
  printf("Digite o número desejado de Contratorpedeiros: ");
  scanf("%d", &ctrtorp);
  printf("Digite o número desejado de Porta-aviões: ");
  scanf("%d", &portAv);

  total_nav = navTanq+subm+ctrtorp+portAv;
  if (total_nav == 0) {
    printf("O mar está calmo capitão, é hora de voltar para casa! \n");
    exit(1);
  }  
  
  //Chama as funções para iniciar o jogo.
  ZeraTabuleiro(jogador1,larg,alt);
  ZeraTabuleiro(jogador2,larg,alt);
  ZeraTabuleiro(Aux1,larg,alt);
  ZeraTabuleiro(Aux2,larg,alt);
  SorteiaNavios(Aux1,larg,alt,navTanq,subm,ctrtorp,portAv);
  SorteiaNavios(Aux2,larg,alt, navTanq, subm, ctrtorp, portAv);
  
  do {
    printf("Escolha o modo de jogo:\n");
    printf("1 = Pessoa vs Pessoa\n2 = Pessoa vs Maquina\n");
    printf("Digite o modo de jogo:");
    scanf("%d", &modo);
    if (modo == 1 || modo == 2) {
      break;
    } else {
      printf("\nEsse modo não existe, digite novamente. \n");
    }
  } while (modo != 1 || modo != 2);

  system("clear"); //limpa a tela

  tempo_inicio = time(NULL); //inicia a contagem do tempo.
  if (modo == 1) {
    Normal(jogador1,Aux1,jogador2,Aux2,navTanq,subm,ctrtorp,portAv,alt,larg);
  } else if (modo == 2) {
    IntArt(jogador1,Aux1,jogador2,Aux2,navTanq,subm,ctrtorp,portAv,alt,larg);
  }

  tempo_final = time(NULL); //finaliza a contagem do tempo
  Tempo(tempo_inicio, tempo_final);//chama a função que organiza o valor obtido
  LiberaMemoria(jogador1, jogador2, Aux1, Aux2, alt);
}