//funções dos slides
typedef struct lista Lista;

Lista* lst_cria();

int lst_vazia(Lista *l);

Lista* lst_insere(Lista *l, int info);

Lista* lst_busca(Lista *l, int info);

void lst_imprime(Lista *l);

Lista* lst_remove(Lista *l, int info);

void lst_libera(Lista *l);

void lst_imprime_invertida_rec(Lista* l);

//funções do trabalho
Lista* lst_ordena_crescente(Lista *l);
