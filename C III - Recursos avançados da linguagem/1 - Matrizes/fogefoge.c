#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

char** mapa;
int linhas;
int colunas;

void liberamapa() {
	int i;
	for (i = 0; i < linhas; i++) {
		free(mapa[i]);
	}
	
	free(mapa);
}

void alocamapa() {
	int i;
	mapa = malloc(sizeof(char*) * linhas);
	
	for (i = 0; i < linhas; i++) {
		mapa[i] = malloc(sizeof(char) * (colunas + 1));
	}
}

void lemapa() {
	FILE* f;
	f = fopen("mapa.txt", "r");
	
	if (f == 0) {
		printf("Erro na leitura do mapa\n");
		exit(1);
	}
	
	fscanf(f, "%d %d", &linhas, &colunas);
	
	alocamapa();
	
	int i;
	for (i = 0; i < 5; i++) {
		fscanf(f, "%s", mapa[i]);
	}
	
	fclose(f);
}

int main() {
	lemapa();
	
	int i;
	for (i = 0; i < 5; i++) {
		printf("%s\n", mapa[i]);
	}
	
	liberamapa();
}
