#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"
#include "ui.h"

MAPA m;
POSICAO heroi;
int tempilula = 0;

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

    if (ehpersonagem(&m, PILULA, proximox, proximoy)) {
        tempilula = 1;
    }

    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}

void gatilhoexplodepilula() {
    if (!tempilula) return;

    explodepilula(heroi.x, heroi.y, 0, 1, 3);
    explodepilula(heroi.x, heroi.y, 0, -1, 3);
    explodepilula(heroi.x, heroi.y, 1, 0, 3);
    explodepilula(heroi.x, heroi.y, -1, 0, 3);

    tempilula = 0;
}

void explodepilula(int x, int y, int somax, int somay, int qtd) {
    if (qtd == 0) return;

    int novox = x + somax;
    int novoy = y + somay;

    if (!valida(&m, novox, novoy)) return;
    if (parede(&m, novox, novoy)) return;

    m.matriz[novox][novoy] = VAZIO;
    explodepilula(novox, novoy, somax, somay, qtd - 1);
}

int main() {
	lemapa(&m);
	
	do {
		imprimemapa(&m);

        encontramapa(&m, &heroi, HEROI);
		
		char comando;
		scanf(" %c", &comando);
		move(comando);

        if (comando == BOMBA) gatilhoexplodepilula();

        fantasmas();
		
	} while(!acabou());
	
	liberamapa(&m);
}
