#ifndef PARSER_ARVORE_H
#define PARSER_ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "tabela_simbolos.h"
//#include "global.h"
#define MAX 1000

typedef enum data{
    INTEIRO,
    VAZIO
} Tipo_dado;

//tipo de no
typedef enum tipo_no{
    DECLARACAO,
    EXPRESSAO,
    NADA
} Tipo_no;

//tipo de declaracao
typedef enum tipo_decl{
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
typedef enum tipo_expr{
    OPERANDO, // Operando.
    OPERADORRELACIONAL, // Operador relacional.
    CONSTANTE, // Valor numérico constante.
    IDK, // Uso de variável.
    CHAMADAFUNCAO, // Chamada de função.
    VETORPARAMETROK, // Uso de parâmetro vetor.
    ATRIBUICAOK, // Atribuição.
    NULO // Nulo.
} Tipo_expressao;

typedef struct Arvore {
    Tipo_declaracao* tipodeclaracao;
    Tipo_expressao* tipoexpressao;
    Tipo_no* tipo;
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
