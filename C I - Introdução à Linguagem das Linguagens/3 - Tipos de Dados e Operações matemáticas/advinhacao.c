#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
    // imprime cabecalho do nosso jogo
	printf("******************************************\n");
	printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
	printf("******************************************\n");
	
	int segundos = time(0);
	srand(segundos);
	
	int numerosecreto = rand() % 100;
	int numerodetentativas = 5;
	int chute;
	int ganhou = 0;
	int tentativas = 1;
	double pontos = 1000;
	
	while (!ganhou) {
		printf("Tentativa %d\n", tentativas);
		printf("Qual é o seu chute?\n");
		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);
		
		if (chute < 0) {
			printf("Você não pode chutar números negativos!\n");
			continue;
		}
		
		int acertou = (chute == numerosecreto);
		int maior = (chute > numerosecreto);
		
		if (acertou) {
			printf("Parabéns! Você acertou\n");
			printf("Jogue de novo, você é um bom jogador!\n");
			printf("Fim de jogo!\n");
			printf("Você acertou em %d tentativas\n", tentativas);	
			ganhou = 1; // equivalente ao break
		} else if (maior) {
			printf("Seu chute foi maior que o número secreto\n\n");
		} else {
			printf("Seu chute foi menor que o número secreto\n\n");
		}
		tentativas++;
		
		double pontosperdidos = (double)abs(chute - numerosecreto) / 2;

		pontos = pontos - pontosperdidos;
	}
	
	printf("Pontos: %.2f", pontos);
	
	
	return 0;
}
