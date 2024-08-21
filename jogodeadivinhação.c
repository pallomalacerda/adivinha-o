#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_TENTATIVAS 3

void game() {
  printf("\n\n");
  printf("          P  /_\\  P                              \n");
  printf("         /_\\_|_|_/_\\                            \n");
  printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
  printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
  printf("    |\" \"  |  |_|  |\"  \" |                     \n");
  printf("    |_____| ' _ ' |_____|                         \n");
  printf("          \\__|_|__/                              \n");
  printf("\n\n");

  int chute;
  double pontos = 1000;

  int nivel;
  int totaldetentativas;

  int acertou;

  srand(time(0));
  int numerosecreto = rand() % 100;

  printf("Qual o nível de dificuldade?\n");
  printf("(1) Fácil (2) Médio (3) Difícil\n\n");
  printf("Escolha: ");

  scanf("%d", &nivel);

  if (nivel == 1) {
    totaldetentativas = 20;
  } else if (nivel == 2) {
    totaldetentativas = 15;
  } else {
    totaldetentativas = 6;
  }

  for (int i = 1; i <= totaldetentativas; i++) {

    printf("Tentativas %d de %d\n", i, totaldetentativas);

    printf("Qual é o seu %d chute? ", i);
    scanf("%d", &chute);

    if (chute < 0) {
      printf("Você não pode chutar números negativos\n");
      continue;
    }

    printf("Seu %d chute foi %d\n", i, chute);

    int acertou = chute == numerosecreto;
    int maior = chute > numerosecreto;

    if (acertou) {
      printf("Parabéns! Você acertou!\n");
      break;
    } else if (maior) {
      printf("Seu chute foi maior do que o número secreto!\n");
    } else {
      printf("Seu chute foi menor do que o número secreto!\n");
    }

    double pontosperdidos = abs(chute - numerosecreto) / 2.0;
    pontos = pontos - pontosperdidos;
  }
printf("\n");
  if(acertou) {
    printf("Você fez %.2f pontos", pontos);
    printf(" Obrigado por jogar!\n");
  }
  else{
    printf("       \\|/ ____ \\|/    \n");   
    printf("        @~/ ,. \\~@      \n");   
    printf("       /_( \\__/ )_\\    \n");   
    printf("          \\__U_/        \n");
  }
 
}

int main() {
  while (1) {
    int option;
    game();
    printf("Jogar Novamente?\n");
    printf("(1) Sim (2) Não\n\n");
    printf("Escolha: ");
    scanf("%d", &option);
    if (option == 2) {
      break;
    }
  }
}