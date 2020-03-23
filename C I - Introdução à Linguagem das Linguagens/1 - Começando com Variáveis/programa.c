#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
    // imprime cabecalho do nosso jogo
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");
    
    int numerosecreto = 42;
	int chute;
	
	printf("Qual é o seu chute?\n");
	scanf("%d", &chute);
	printf("Seu chute foi %d\n", chute);
}
