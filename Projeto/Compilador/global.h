#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


extern int linhaatual;

typedef struct arvore {
    char* tipo;
    char* valor;
    struct arvore* filho;
    struct arvore* irmao;
} Arvore;


Buffer *buffer = NULL;
Lex *lex = NULL;
FILE *input_file = NULL;

char* pega_carac = NULL;


char letra = '\0';
char c = '\0';
int linha_atual = 0;
int controle = 0;
    
