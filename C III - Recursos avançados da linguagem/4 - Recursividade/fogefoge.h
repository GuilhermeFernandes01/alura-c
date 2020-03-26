#define CIMA 'w'
#define ESQUERDA 'a'
#define BAIXO 's'
#define DIREITA 'd'
#define BOMBA 'b'

int acabou();
void move(char direcao);
void fantasmas();
int destinofantasma(int xatual, int yatual, int* xdestino, int* ydestino);
void explodepilula(int x, int y, int somax, int somay, int qtd);
void gatilhoexplodepilula();
