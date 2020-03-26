#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

struct mapa {
	char** matriz;
	int linhas;
	int colunas;
};

typedef struct mapa MAPA;

struct posicao {
	int x;
	int y;
};

typedef struct posicao POSICAO;

void liberamapa(MAPA* m);
void alocamapa(MAPA* m);
void lemapa(MAPA* m);
void imprimemapa(MAPA* m);
int encontramapa(MAPA* m, POSICAO* p, char c);
int valida(MAPA* m, int x, int y);
int vazia(MAPA* m, int x, int y);
int podeandar(MAPA* m, char personagem, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);
int parede(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);
