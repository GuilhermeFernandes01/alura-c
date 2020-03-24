#include <stdio.h>
#include <string.h>
#include <locale.h>

void abertura() {
	printf("****************************************\n");
	printf("*            Jogo de Forca             *\n");
	printf("****************************************\n\n");
}

void chuta(char chutes[26], int tentativas) {
	char chute;
	scanf(" %c", &chute);
	
	chutes[tentativas] = chute;
	tentativas++;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char palavrasecreta[20];
	char chutes[26];
	int tentativas = 0;
	
	sprintf(palavrasecreta, "MELANCIA");
	
	int acertou = 0;
	int enforcou = 0;
	
	abertura();
	
	do {
		int i;
		for (i = 0; i < strlen(palavrasecreta); i++) {
			int j;
			int achou = 0;
			for (j = 0; j < tentativas; j++) {
				if (chutes[j] == palavrasecreta[i]) {
					achou = 1;
					break;
				}
			}
			if (achou) {
				printf("%c ", palavrasecreta[i]);
			} else {
				printf("_ ");
			}
		}
		printf("\n");
		chuta(chutes, tentativas);
		
	} while (!enforcou && !acertou);
}
