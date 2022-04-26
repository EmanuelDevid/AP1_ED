//funções dos slides
typedef struct lista Lista;

Lista* lst_cria();

int lst_vazia(Lista *l);

Lista* lst_insere(Lista *l, int info);

Lista* lst_busca(Lista *l, int info);

void lst_imprime(Lista *l);

Lista* lst_remove(Lista *l, int info);

void lst_libera(Lista *l);

Lista* lst_remove_rec(Lista *l, int info);

void lst_imprime_invertida_rec(Lista* l);

//funções do trabalho
int comprimento(Lista* l);

int menores(Lista* l, int n);

int soma(Lista* l);

int primos(Lista* l);

Lista* lst_inverte(Lista *l);

Lista* lst_conc(Lista* l1, Lista* l2);

Lista* lst_diferenca(Lista* l1, Lista* l2);
