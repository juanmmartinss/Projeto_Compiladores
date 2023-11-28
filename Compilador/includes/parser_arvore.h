#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arvore {
    char* tipo;
    char* valor;
    char lexema[25];
    struct Arvore* filho1;
    struct Arvore* filho2;
    struct Arvore* filho3;
    struct Arvore* irmao;
} Arvore;

typedef Arvore *pont_arv;

pont_arv cria_no(pont_arv no);
pont_arv insere_irmao(pont_arv raiz, pont_arv no);
pont_arv insere_filho(pont_arv raiz, pont_arv no);
void imprime_arvore(pont_arv raiz, int nivel);
void libera_arvore_sintatica(pont_arv raiz);
