#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int destinofantasma(int xatual, int yatual, int* xdestino, int* ydestino) {
    int opcoes[4][2] = {
        { xatual, yatual + 1 },
        { xatual + 1, yatual },
        { xatual, yatual - 1 },
        { xatual - 1, yatual }
    };

    srand(time(0));

    int i;
    for (i = 0; i < 10; i++) {
        int posicao = rand() % 4;
        
        if (podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];

            return 1;
        }
    }

    return 0;
}

void fantasmas() {
    MAPA copia;

    copiamapa(&copia, &m);

    for(int i = 0; i < copia.linhas; i++) {
        for(int j = 0; j < copia.colunas; j++) {
            if(copia.matriz[i][j] == FANTASMA) {

                int xdestino;
                int ydestino;

                int encontrou = destinofantasma(i, j, &xdestino, &ydestino);

                if(encontrou) {
                    andanomapa(&m, i, j, xdestino, ydestino);
                }
            }
        }
    }

    liberamapa(&copia);
}

int acabou() {
    POSICAO pos;

    int fogefogenomapa = encontramapa(&m, &pos, HEROI);

    return !fogefogenomapa;
}

void move(char direcao) {
    int proximox = heroi.x;
    int proximoy = heroi.y;

	switch(direcao) {
        case CIMA:
            proximox--;
            break;
        case ESQUERDA:
            proximoy--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;
        default:
            return;
    }

    if (!podeandar(&m, HEROI, proximox, proximoy)) return;

    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}

int main() {
	lemapa(&m);
	
	do {
		imprimemapa(&m);

        encontramapa(&m, &heroi, HEROI);
		
		char comando;
		scanf(" %c", &comando);
		move(comando);
        fantasmas();
		
	} while(!acabou());
	
	liberamapa(&m);
}
