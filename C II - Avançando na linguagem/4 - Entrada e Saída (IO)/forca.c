#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

void abertura() {
	printf("****************************************\n");
	printf("*            Jogo de Forca             *\n");
	printf("****************************************\n\n");
}

void chuta(char chutes[26]) {
	char chute;
	scanf(" %c", &chute);
	
	chutes[chutesdados] = chute;
	chutesdados++;
}

int jachutou(char letra) {
	int achou = 0;
	int j;
	
	for (j = 0; j < chutesdados; j++) {
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
	FILE* f;
	f = fopen("palavras.txt", "r");
	
	if (f == 0) {
		printf("Desculpe, banco de dados não disponível\n\n");
		exit(1);
	}
	
	int qtdpalavras;
	fscanf(f, "%d", &qtdpalavras);
	printf("%d", qtdpalavras);
	
	srand(time(0));
	int randomico = rand() % qtdpalavras;
	
	int i;
	for (i = 0; i <= randomico; i++) {
		fscanf(f, "%s", palavrasecreta);
	}
	
	
	fclose(f);
}

void adicionapalavra() {
    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer);

    if (quer == 'S') {
        char novapalavra[20];

        printf("Digite a nova palavra, em letras maiúsculas: ");
        scanf("%s", novapalavra);

        FILE* f;
		f = fopen("palavras.txt", "r+");
        
		if(f == 0) {
            printf("Banco de dados não disponível\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}

int enforcou() {
	int i;
	int erros = 0;
	for (i = 0; i < chutesdados; i++) {
		int existe = 0;
		int j;
		for (j = 0; j < strlen(palavrasecreta); j++) {
			if (chutes[i] == palavrasecreta[j]) {
				existe = 1;
				break;
			}
		}
		if (!existe) erros++;
	}
	
	return erros >= 5;
}

int ganhou() {
	int i;
	for (i = 0; i < strlen(palavrasecreta); i++) {
		if (!jachutou(palavrasecreta[i])) {
			return 0;
		}
	}
	return 1;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	escolhepalavra();
		
	abertura();
	
	do {
		desenhaforca();
		
		chuta(chutes);
		
	} while (!ganhou() && !enforcou());
	
	adicionapalavra();
}
