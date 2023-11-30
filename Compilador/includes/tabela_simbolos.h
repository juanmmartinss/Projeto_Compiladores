#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "global.h"

typedef struct item_tabela {
    char *nome;
    char *tipo;
    int escopo;
    int linha;
    int coluna;
    struct item *prox;
} Item_tabela;

typedef Item_tabela *Tabela;

