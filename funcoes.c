#include <stdio.h>

#include "funcoes.h"


#define porta_aviao 'P'
#define navio_tanque 'N'
#define contratorpedeiro 'C'
#define submarino 'S'


int FazSorteio(int n)
{
  return rand() % n;
}

void imprime(char **tab, int lin, int col, int nrTab)
{
  int conta_col=0;

  printf("\n");
  for (int i=0;i<col+((col/3)+1);i++) printf(" ");
  printf("» TABULEIRO DO JOGADOR %d « \n\n", nrTab);
  printf("Coluna→");
  printf("    ");

  for (int j=0;j<col;j++) {
    printf("%d  ", j);
  }
  printf("\n");
  printf("Linha↓");
  printf("    ");
  for (int k=0;k<col;k++) {
    if (k<9) {
      printf("===");
    } else {
      printf("====");
    }
  }
  printf("\n");
 
  for (int m=0;m<lin;m++) {
    if (m < 10) {
      printf("     ");
      printf("%d", m);
      printf("   ");
      printf("| ");
      for (int n=0;n<col;n++) {
        if (n<10) {
          printf("%c  ", tab[m][n]);
        } else {
          printf("%c   ", tab[m][n]);
        }
        conta_col++;
      }
      printf("|");
      printf("\n");
    } else {
      conta_col = 0;
      printf("    ");
      printf("%d", m);
      printf("   ");
      printf("| ");
      for (int n=0;n<col;n++) {
        if (conta_col < 10) {
          printf("%c  ", tab[m][n]);
        } else {
          printf("%c   ", tab[m][n]);
        }
        conta_col++;
      }
      printf("|");
      printf("\n");
    }
  }
  printf("          ");
  for (int p=0;p<col;p++) {
    if (p<9) {
      printf("===");
    } else {
      printf("====");
    }
  }
  printf("\n");
}

int JogadaIA(char **tab, char **aux, int larg, int alt, int col, int lin, int vida)
{
  int salva_vida = vida;
  int xlin = 999;
  int xcol = 999;
  int sortlin = FazSorteio(alt);
  int sortcol = FazSorteio(larg);
  int sorteiapos = FazSorteio(4); // 0 cima - 1 baixo / 2 esq - 3 dir
  for (int i=0;i<alt;i++) {
    for (int j=0;j<larg;j++) {
      if (tab[i][j] == '@') {
        xlin = i;
        xcol = j;
      }
    }
  }
  if (xlin != 999) {
    if (sorteiapos == 0 && xlin-1 >= 0) {
      if (tab[xlin-1][xcol] == '~') {
        tab[xlin-1][xcol] = '*';
        aux[xlin-1][xcol] = '*';
        printf("A máquina jogou nas posições:coluna %d - linha %d\n", xcol, xlin);
      } else if (tab[xlin-1][xcol] == '*' || tab[xlin-1][xcol] == '@') {
        JogadaIA(tab, aux, larg, alt, col, lin, vida);
      } else if (tab[xlin-1][xcol] == 'S' || tab[xlin-1][xcol] == 'N' ||
          tab[xlin-1][xcol] == 'P' || tab[xlin-1][xcol] == 'C') {
        tab[xlin-1][xcol] = '@';
        aux[xlin-1][xcol] = '@';
        printf("A máquina jogou nas posições:coluna %d - linha %d\n", xcol, xlin);
      } else {
        JogadaIA(tab, aux, larg, alt, col, lin, vida);
      }
    } else if (sorteiapos == 1 && xlin+1 <= alt) {
      if (tab[xlin+1][xcol] == '~') {
        tab[xlin+1][xcol] = '*';
        aux[xlin+1][xcol] = '*';
        printf("A máquina jogou nas posições:coluna %d - linha %d\n", xcol, xlin);
      } else if (tab[xlin+1][xcol] == '*' || tab[xlin+1][xcol] == '@') {
        JogadaIA(tab, aux, larg, alt, col, lin, vida);
      } else if (tab[xlin+1][xcol] == 'S' || tab[xlin+1][xcol] == 'N' ||
          tab[xlin+1][xcol] == 'P' || tab[xlin+1][xcol] == 'C') {
        tab[xlin+1][xcol] = '@';
        aux[xlin+1][xcol] = '@';
        printf("A máquina jogou nas posições:coluna %d - linha %d\n", xcol, xlin);
      } else {
        JogadaIA(tab, aux, larg, alt, col, lin, vida);
      }
    } else if (sorteiapos == 2 && xcol-1 >= 0) {
      if (tab[xlin][xcol-1] == '~') {
        tab[xlin][xcol-1] = '*';
        aux[xlin][xcol-1] = '*';
        printf("A máquina jogou nas posições:coluna %d - linha %d\n", xcol, xlin);
      } else if (tab[xlin][xcol-1] == '*' || tab[xlin][xcol-1] == '@') {
        JogadaIA(tab, aux, larg, alt, col, lin, vida);
      } else if (tab[xlin][xcol-1] == 'S' || tab[xlin][xcol-1] == 'N' ||
          tab[xlin][xcol-1] == 'P' || tab[xlin][xcol-1] == 'C') {
        vida--;
        printf("A máquina jogou nas posições:coluna %d - linha %d\n", xcol, xlin);
      } else {
        JogadaIA(tab, aux, larg, alt, col, lin, vida);
      }  
    } else if (sorteiapos == 3 && xcol+1 <= larg) {
      if (tab[xlin][xcol+1] == '~') {
        tab[xlin][xcol+1] = '*';
        aux[xlin][xcol+1] = '*';
        printf("A máquina jogou nas posições:coluna %d - linha %d\n", xcol, xlin);
      } else if (tab[xlin][xcol+1] == '*' || tab[xlin][xcol+1] == '@') {
        JogadaIA(tab, aux, larg, alt, col, lin, vida);
      } else if (tab[xlin][xcol+1] == 'S' || tab[xlin][xcol+1] == 'N' ||
          tab[xlin][xcol+1] == 'P' || tab[xlin][xcol+1] == 'C') {
        vida--;
        printf("A máquina jogou nas posições:coluna %d - linha %d\n", xcol, xlin);
      } else {
        JogadaIA(tab, aux, larg, alt, col, lin, vida);
      }
    }
  } else {
    if (tab[sortlin][sortcol] == '~') {
      tab[sortlin][sortcol] = '*';
      aux[sortlin][sortcol] = '*';
      printf("A máquina jogou nas posições:coluna %d - linha %d\n", xcol, xlin);
    } else if (tab[sortlin][sortcol] == '*' || tab[sortlin][sortcol] == '@') {
      JogadaIA(tab, aux, larg, alt, col, lin, vida);
    } else if (tab[sortlin][sortcol] == 'S' || tab[sortlin][sortcol] == 'N' ||
        tab[sortlin][sortcol] == 'P' || tab[sortlin][sortcol] == 'C') {
      tab[sortlin][sortcol] = '@';
      aux[sortlin][sortcol] = '@';
      vida--;
      printf("A máquina jogou nas posições:coluna %d - linha %d\n", xcol, xlin);
    }
  }
  return vida;
}

int VerificadorH(char **tab, int lin, int col, int n, int larg)
{
  int contD=0, contE=0;
  for (int i=0;i<n;i++) {
    if (col+i<=larg && col+i<=n && tab[lin][col+i]=='~' && (tab[lin][col+i]!='P' &&
        tab[lin][col+i]!='N' && tab[lin][col+i]!='C' && tab[lin][col+i]!='S')){
      contD++;
    }
  }
  for (int j=0;j<n;j++) {
    if (col-j>=0 && col-j>=0 && tab[lin][col-j]=='~' && (tab[lin][col-j]!='P' &&
       tab[lin][col-j]!='N' && tab[lin][col-j]!='C' && tab[lin][col-j]!='S')) {
      contE++;
    }
  }
  if (contD == n && contD > contE) {
    return 1;
  } else if (contE == n && contD < contE) {
    return 0;
  } else if (contD == n && contD == contE) {
    return FazSorteio(2);
  } else {
    return 999;
  }
}

int VerificadorV(char **tab, int lin, int col, int n, int alt)
{
  int contC=0, contB=0;
  for (int i=0;i<n;i++) {
    if (lin+i<=alt && lin+i<n && tab[lin+i][col]=='~' && (tab[lin+i][col]!='P' &&
        tab[lin+i][col]!='N' && tab[lin+i][col]!='C' && tab[lin+i][col]!='S')){
      contC++;
    }
  }
  for (int j=0;j<n;j++) {
    if (lin-j>=0 && lin-j>=0 && tab[lin-j][col]=='~' && (tab[lin-j][col]!='P' &&
        tab[lin-j][col]!='N' && tab[lin-j][col]!='C' && tab[lin-j][col]!='S')){
      contB++;
    }
  }
  if (contC == n && contC > contB) {
    return 1;
  } else if (contB == n && contC < contB) {
    return 0;
  } else if (contB == n && contB == contC) {
    return FazSorteio(2);
  } else {
    return 999;
  }
}

void ZeraTabuleiro(char **tab, int larg, int alt)
{
  for (int i=0; i<alt; i++) {
    for (int j=0; j<larg; j++) {
      tab[i][j] = '~';
    }
  }
}

int recebeLarg()
{
  int larg = 0;
  printf("Digite (usando números inteiros) a LARGURA desejada do tabuleiro: ");
  do {
    scanf("%d", &larg);
    if (larg <= 0) {
      printf("Largura muito pequena, digite novamente.\n");
    }
  } while (larg<=0);
  return larg;
}

int recebeAlt()
{
  int alt = 0;
  printf("Digite (usando números inteiros) a ALTURA desejada do tabuleiro: ");
  do {
    scanf("%d", &alt);
    if (alt <= 0) {
      printf("Altura muito pequena, digite novamente.\n");
    }
  } while (alt<=0);
  return alt;
}

char** AllocaTabuleiro(int larg, int alt)
{
  char **tab;
  tab = (char **) malloc (alt * sizeof(sizeof(char *)));
  if (tab == NULL) {
    printf("Não foi possível alocar memória.");
  }

  for (int i=0; i<alt; i++) {
    tab[i] = (char *) malloc (larg * sizeof(char));
  }
  return tab;
}

void SortNav(char **tab, int larg, int alt, int qtd_nav, char navio,int tamNav)
{
  //0 - Horizontal | 1 - Vertical
  int cont = 0, salva_col, salva_lin, salva_sort;
  while(cont < qtd_nav) {
    salva_sort = FazSorteio(2);
    if (salva_sort == 0) {
      salva_col = FazSorteio(larg);
      salva_lin = FazSorteio(alt);
      if (VerificadorH(tab, salva_lin, salva_col, tamNav, larg) == 1
        && salva_col+tamNav < larg) {
        for (int i=0;i<tamNav;i++) {
          tab[salva_lin][salva_col+i] = navio;
        }
        cont++;
      } else if (VerificadorH(tab, salva_lin, salva_col, tamNav, larg) == 0
        && salva_col-tamNav >= 0) {
        for (int j=0;j<tamNav;j++) {
          tab[salva_lin][salva_col-j] = navio;
        }
        cont++;
      }
    } else {
      salva_col = FazSorteio(larg);
      salva_lin = FazSorteio(alt);
      if (VerificadorV(tab, salva_lin, salva_col, tamNav, alt) == 1 && 
          salva_lin+tamNav < alt) {
        for (int i=0;i<tamNav;i++) {
          tab[salva_lin+i][salva_col] = navio;
        }
        cont++;
      } else if (VerificadorV(tab, salva_lin, salva_col, tamNav, alt) == 0
       && salva_lin-tamNav >= 0) {
        for (int j=0;j<tamNav;j++) {
          tab[salva_lin-j][salva_col] = navio;
        }
        cont++;
      }
    }
  };
}

void SorteiaNavios(char **tab, int larg, int alt, int nav_tanq, int submar, 
      int contratorp, int porta_av)
{
  SortNav(tab, larg, alt, porta_av, porta_aviao, 5);
  SortNav(tab, larg, alt, nav_tanq, navio_tanque, 4);
  SortNav(tab, larg, alt, contratorp, contratorpedeiro, 3);
  SortNav(tab, larg, alt, submar, submarino, 2);  
}

int FazJogada(char **real, char **aux, int coluna, int linha, int vida, int larg, int alt)
{
  int msg = FazSorteio(5);
  int col = 0, lin = 0;

  if (aux[linha][coluna] != '~' && aux[linha][coluna] != '@' &&
      aux[linha][coluna] != '*') {
    printf("Alvo atingido!\n");
    real[linha][coluna] = '@';
    aux[linha][coluna] = '@';
    vida--;
  } else if (aux[linha][coluna] == '*') {
    printf("Você já mirou ai e não tinha nada, troque de coordenada!\n");
    printf("Digte novamente a coluna seguido da linha: \n");
    do {
        scanf("%d %d", &col, &lin);
        if ((col <0 && col > larg) && (lin < 0 && lin > alt)) {
          printf("Você ultrapassou o tamanho do tabuleiro.\n");
        }
      } while ((col <=0 && col >= larg) && (lin <= 0 && lin >= alt));
    FazJogada(real, aux, col, lin, vida, larg, alt);
  } else if (aux[linha][coluna] == '~') {
    real[linha][coluna] = '*';
    aux[linha][coluna] = '*';
    if (msg == 0) {
      printf("Não foi dessa vez!\n");
    } else if (msg == 1) {
      printf("Baleia atingida! Mas nosso objetivo é acertar o inimigo.\n");
    } else if (msg == 2) {
      printf("Essa foi longe!\n");
    } else if (msg == 3) {
      printf("Aqui capitão, pegue seu óculos e tente novamente!\n");
    } else {
      printf("Você errou, mas fique tranquilo que foi culpa do vento!\n");
    }
  }
  return vida;
}

bool checkaFinal(int vida1, int vida2)
{
  if (vida1 == 0 || vida2 == 0) {
    return true;
  } else {
    return false;
  }
}

void Normal(char **tab1, char** aux1, char **tab2, char **aux2,
      int nav_tanq, int submar, int contratorp, int porta_av, int alt,int larg)
{
  int vida1 = ((5*porta_av)+(4*nav_tanq)+(3*contratorp)+(2*submar));
  int vida2 = ((5*porta_av)+(4*nav_tanq)+(3*contratorp)+(2*submar));
  int qualJogador = 0, coluna = 0, linha = 0;

  printf("\n\nDaremos início à batalha naval! \n\n");
  printf("\nVocê escolheu jogar contra outro jogador, boa sorte! \n");

  printf("Será escolhido aleatoriamente um jogador para começar.\n");
  qualJogador = FazSorteio(2);
  if (qualJogador % 2 == 0) {
    printf("O jogador 1 começará!\n");
  } else {
    printf("O jogador 2 começará! \n");
  }

  while (!checkaFinal(vida1, vida2)) {
    if (qualJogador % 2 == 0) {
      imprime(aux1, alt, larg, 1);
      imprime(tab2, alt, larg, 2);
      printf("\n\n.:: É a vez do jogador 1 ::. \n");
      do {
        printf("Capitão, informe as coordenadas do ataque!\n");
        printf("Digite a coluna seguido da linha \n");
        scanf("%d %d", &coluna, &linha);
        if ((coluna <=0 && coluna >= larg) && (linha <= 0 && linha >= alt)) {
          printf("Você ultrapassou o tamanho do tabuleiro.\n");
        }
      } while ((coluna >0 && coluna < larg) && (linha > 0 && linha < alt));
      vida2 = FazJogada(tab2, aux2, coluna, linha, vida2, larg, alt);
      printf("vida do jogador 1: %d | vida do jogador 2: %d \n", vida1, vida2);
      qualJogador++;
    } else {
      imprime(aux2, alt, larg, 2);
      imprime(tab1, alt, larg, 1);
      printf("\n\n.:: É a vez do jogador 2 ::. \n");
      do {
        printf("Capitão, informe as coordenadas do ataque!\n");
        printf("Digite a coluna seguido da linha \n");
        scanf("%d %d", &coluna, &linha);
        if ((coluna <0 && coluna > larg) && (linha < 0 && linha > alt)) {
          printf("Você ultrapassou o tamanho do tabuleiro.\n");
        }
      } while ((coluna <0 && coluna > larg) && (linha < 0 && linha > alt));
      vida1 = FazJogada(tab1, aux1, coluna, linha, vida1, larg, alt);
      printf("vida do jogador 1: %d | vida do jogador 2: %d \n", vida1, vida2);
      qualJogador++;
    }
  };
  if (vida1 == 0) {
    imprime(aux1, alt, larg, 1);
    imprime(aux2, alt, larg, 2);
    printf("É hora de comemorar Capitão, nós ganhamos do jogador 1! \n");
  } else if (vida2 == 0) {
    imprime(aux1, alt, larg, 1);
    imprime(aux2, alt, larg, 2);
    printf("É hora de comemorar Capitão, nós ganhamos do jogador 2! \n");
  }
  
}

void IntArt(char **tab1, char** aux1, char **tab2, char **aux2,
      int nav_tanq, int submar, int contratorp, int porta_av, int alt,int larg)
{
  int vida1 = ((5*porta_av)+(4*nav_tanq)+(3*contratorp)+(2*submar));
  int vida2 = ((5*porta_av)+(4*nav_tanq)+(3*contratorp)+(2*submar));
  int qualJogador = 0, coluna = 0, linha = 0;
  int col = 0, lin = 0;
  int salva_vida = vida1;
  
  col = FazSorteio(larg);
  lin = FazSorteio(alt);

  printf("\n\nDaremos início à batalha naval! \n\n");
  printf("\nVocê escolheu jogar contra o computador, boa sorte! \n");

  printf("Será escolhido aleatoriamente um jogador para começar.\n");
  qualJogador = FazSorteio(2);
  if (qualJogador % 2 == 0) {
    printf("O jogador 1 começará!\n");
  } else {
    printf("O jogador 2 começará! \n");
  }

  while (!checkaFinal(vida1, vida2)) {
    if (qualJogador % 2 == 0) {
      imprime(aux1, alt, larg, 1);
      imprime(tab2, alt, larg, 2);
      printf("\n\n.:: É a vez do humano ::. \n");
      do {
        printf("Capitão, informe as coordenadas do ataque!\n");
        printf("Digite a coluna seguido da linha \n");
        scanf("%d %d", &coluna, &linha);
        if ((coluna <=0 && coluna >= larg) && (linha <= 0 && linha >= alt)) {
          printf("Você ultrapassou o tamanho do tabuleiro.\n");
        }
      } while ((coluna <0 && coluna > larg) && (linha < 0 && linha > alt));
      vida2 = FazJogada(tab2, aux2, coluna, linha, vida2, larg, alt);
      qualJogador++;
    } else {
      printf("\n\n.:: É a vez da máquina ::. \n");
      vida1 = JogadaIA(aux1, tab1, larg, alt, lin, col, vida1);
      printf("vida do humano: %d | vida da máquina: %d \n", vida1, vida2);
      qualJogador++;
    }
  };
  if (vida1 == 0) {
    system("clear");
    imprime(aux1, alt, larg, 1);
    imprime(aux2, alt, larg, 2);
    printf("\nA máquina venceu, estamos afundando! \n");
  } else if (vida2 == 0) {
    system("clear");
    imprime(aux1, alt, larg, 1);
    imprime(aux2, alt, larg, 2);
    printf("\nÉ hora de comemorar Capitão, nós afundamos a máquina! \n");
  }
  
}

void Tempo(time_t tempo_inicio, time_t tempo_final)
{
  time_t tempo_decorrido;
  tempo_decorrido = tempo_final - tempo_inicio;
  int hr, min, seg;
  float sec_aux = tempo_decorrido/60;
  if (tempo_decorrido < 60) {
    printf("O jogo durou %ld segundos.\n", tempo_decorrido);
  } else if (tempo_decorrido > 60) {
    min = tempo_decorrido/60;
    seg = (sec_aux-min)*60;
    printf("O jogo durou %d minutos e %d segundos.\n", min, seg);
  } else {
    hr = tempo_decorrido/3600;
    min = tempo_decorrido/60;
    seg = (sec_aux-min)*60;
    printf("o jogo durou %d horas, %d minutos e %d segundos.\n", hr, min, seg);
  }
}

void LiberaMemoria(char **tab1, char **tab2, char **tab3, char **tab4, int alt)
{
  for (int i=0; i<alt;i++) {
    free(tab1[i]);
    free(tab2[i]);
    free(tab3[i]);
    free(tab4[i]);
  }
  free(tab1);
  free(tab2);
  free(tab3);
  free(tab4);
}
