#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int linhaatual;

typedef enum {
    INTEIRO,
    VAZIO
} Tipo_dado;

//tipo de no
typedef enum {
    DECLARACAO,
    EXPRESSAO,
    NADA
} Tipo_no;

//tipo de declaracao
typedef enum {
    IFK, 
    WHILEK, 
    INTK, 
    VOIDK, 
    NULOK, 
    VARIAVELK, 
    VETORK, 
    FUNCAOK, 
    PARAMETROVARIAVELK,
    PARAMETROVETORK,
    PARAMETROVOIDK 
} Tipo_declaracao;

//tipo de expressao
typedef enum {
    OPERANDO, // Operando.
    OPERADORRELACIONAL, // Operador relacional.
    CONSTANTE, // Valor numérico constante.
    IDK, // Uso de variável.
    CHAMADAFUNCAO, // Chamada de função.
    VETORPARAMETROK, // Uso de parâmetro vetor.
    ATRIBUICAOK, // Atribuição.
    NULO // Nulo.
} Tipo_expressao;

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
    
