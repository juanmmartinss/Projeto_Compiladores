#ifndef GLOBAL_H
#define GLOBAL_H

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


extern Buffer *buffer;
extern Lex *lex;
extern FILE *input_file;

extern char* pega_carac;


extern char letra;
extern char c ;
extern int linha_atual;
extern int controle;

#endif
    
