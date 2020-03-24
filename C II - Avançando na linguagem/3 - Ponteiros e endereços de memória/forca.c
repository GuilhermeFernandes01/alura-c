#include <stdio.h>
#include <string.h>
#include <locale.h>

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

void abertura() {
	printf("****************************************\n");
	printf("*            Jogo de Forca             *\n");
	printf("****************************************\n\n");
}

void chuta(char chutes[26]) {
	char chute;
	scanf(" %c", &chute);
	
	chutes[tentativas] = chute;
	tentativas++;
}

int jachutou(char letra) {
	int achou = 0;
	int j;
	
	for (j = 0; j < tentativas; j++) {
		if (chutes[j] == letra) {
			achou = 1;
			break;
		}
	}
	
	return achou;
}

void desenhaforca() {
	int i;
	for (i = 0; i < strlen(palavrasecreta); i++) {
		int achou = jachutou(palavrasecreta[i]);
		
		if (achou) {
			printf("%c ", palavrasecreta[i]);
		} else {
			printf("_ ");
		}
	}
	printf("\n");
}

void escolhepalavra() {
	sprintf(palavrasecreta, "MELANCIA");
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int acertou = 0;
	int enforcou = 0;
	
	escolhepalavra();
		
	abertura();
	
	do {
		desenhaforca();
		
		chuta(chutes);
		
	} while (!enforcou && !acertou);
}
