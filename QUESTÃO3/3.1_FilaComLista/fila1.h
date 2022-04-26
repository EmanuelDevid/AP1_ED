//funções dos slides
typedef struct fila Fila;

Fila* fila_cria(void);

int fila_vazia(Fila *f);

void fila_insere(Fila *f, int info);

int fila_remove(Fila *f);

void fila_imprime(Fila *f);

void fila_libera(Fila *f);

//funções do trabalho
int qtd_maior(Fila* f, int n);

Fila* inverte(Fila* f);

int pares(Fila* f);
