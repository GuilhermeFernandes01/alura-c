#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

char palavrasecreta[TAMANHO_PALAVRA];
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
	int erros = chuteserrados();
	
	printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c \n", erros >= 1 ? '(' : ' ', erros >= 1 ? '_' : ' ', erros >= 1 ? ')' : ' ');
    printf(" |      %c%c%c \n", erros >= 3 ? '\\' : ' ', erros >= 3 ? '|' : ' ', erros >= 3 ? '/' : ' ');
    printf(" |       %c    \n", erros >= 2 ? '|' : ' ');
    printf(" |      %c %c   \n", erros >= 4 ? '/' : ' ', erros >= 4 ? '\\' : ' ');
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");
    
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
        char novapalavra[TAMANHO_PALAVRA];

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

int chuteserrados() {
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
	
	return erros;
}

int enforcou() {
	return chuteserrados() >= 5;
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
	
	if (ganhou()) {
		printf("\nParabéns, você ganhou!\n");
		printf("\nA palavra secreta era **%s**\n", palavrasecreta);
		
		printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
	} else {
		printf("\nPuxa, você foi enforcado!\n");
		printf("\nA palavra secreta era **%s**\n", palavrasecreta);
		
		printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
	}
	
	adicionapalavra();
}
