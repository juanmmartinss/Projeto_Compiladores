#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int linhaatual;

// typedef struct Arvore {
//     char* tipo;
//     char* valor;
//     char lexema[25];
//     struct Arvore* filho1;
//     struct Arvore* filho2;
//     struct Arvore* filho3;
//     struct Arvore* irmao;
// } Arvore;

// typedef Arvore *pont_arv;

//criar um vetor para receber os tokens
//vetor para armazenar todos os lexemas

extern Pilha *pilha;
extern Buffer *buffer;
extern Lex *lex;
extern FILE *input_file;
extern char* pega_carac;
extern char letra;
extern char c ;
extern int linha_atual;
extern int controle;

#endif
    
