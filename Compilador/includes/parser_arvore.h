#ifndef PARSER_ARVORE_H
#define PARSER_ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "global.h"
#define MAX 1000

typedef struct Arvore {
    char* tipodeclaracao;
    char* tipoexpressao;
    char* tipo;
    char* valor;
    char lexema[25];
    struct Arvore* filho1;
    struct Arvore* filho2;
    struct Arvore* filho3;
    struct Arvore* irmao;
} Arvore;

typedef Arvore *pont_arv;

pont_arv parse(void);

pont_arv cria_no(pont_arv no);
pont_arv insere_irmao(pont_arv raiz, pont_arv no);
pont_arv insere_filho(pont_arv raiz, pont_arv no);
void imprime_arvore(pont_arv raiz, int nivel);
void libera_arvore_sintatica(pont_arv raiz);

#endif
