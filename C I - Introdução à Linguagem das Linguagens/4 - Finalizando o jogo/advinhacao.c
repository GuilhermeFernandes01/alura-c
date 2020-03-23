#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
    // imprime cabecalho do nosso jogo
	printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n          Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinhação!\n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");
	
	int segundos = time(0);
	srand(segundos);
	
	int numerosecreto = rand() % 100;
	int chute;
	int ganhou = 0;
	double pontos = 1000;
	
	int acertou = 0;
	int nivel;
	printf("Qual o nível de dificuldade?\n");
	printf("(1) Fácil - (2) Médio - (3) - Díficil\n");
	printf("Escolha: ");
	scanf("%d", &nivel);
	
	int tentativas = 1;
	
	int numerodetentativas;
	switch (nivel) {
		case 1:
			numerodetentativas = 20;
			break;
		case 2:
			numerodetentativas = 15;
			break;
		default:
			numerodetentativas = 7;
			break;
	}
	
	int i;
	for (i = 1; i <= numerodetentativas; i++) {
		printf("Tentativa %d\n", tentativas);
		printf("Qual é o seu chute?\n");
		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);
		
		if (chute < 0) {
			printf("Você não pode chutar números negativos!\n");
			continue;
		}
		
		acertou = (chute == numerosecreto);
		int maior = (chute > numerosecreto);
		
		if (acertou) {
			break;
		} else if (maior) {
			printf("Seu chute foi maior que o número secreto\n\n");
		} else {
			printf("Seu chute foi menor que o número secreto\n\n");
		}
		tentativas++;
		
		double pontosperdidos = (double)abs(chute - numerosecreto) / 2;

		pontos = pontos - pontosperdidos;
	}
	
	printf("Fim de jogo!\n");
	
	if(acertou) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");

        printf("Parabéns! Você ganhou!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);

	} else {
        printf("Você perdeu! Tente de novo!\n");

        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
	}
	
	printf("Pontos: %.2f", pontos);
	
	
	return 0;
}
