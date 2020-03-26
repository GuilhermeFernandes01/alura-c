#define CIMA 'w'
#define ESQUERDA 'a'
#define BAIXO 's'
#define DIREITA 'd'

int acabou();
void move(char direcao);
void fantasmas();
int destinofantasma(int xatual, int yatual, int* xdestino, int* ydestino);
