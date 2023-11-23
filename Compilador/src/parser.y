%{
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "global.h"
//#include "parser.h"

int linhaatual;

//#define YYSTYPE pont_arv;
int parse(void);
int yylex();
int yyparse();
int yyerror(char *s);

//pont_arv raiz;

%}

%expect 1

%token TK_ELSE
%token TK_IF
%token TK_INT
%token TK_RETURN
%token TK_VOID
%token TK_WHILE
%token TK_ID
%token TK_NUM
%token TK_PLUS
%token TK_MINUS
%token TK_TIMES
%token TK_OVER
%token TK_LT
%token TK_LE
%token TK_GT
%token TK_GE
%token TK_EQ
%token TK_NE
%token TK_ASSIGN
%token TK_SEMI
%token TK_COMMA
%token TK_LPAREN
%token TK_RPAREN
%token TK_LBRACKET
%token TK_RBRACKET
%token TK_LBRACE
%token TK_RBRACE
%token TK_MAIN
%token TK_PRINTF

%%

programa: lista_declaracoes
        {printf("PROGRAMA RECONHECIDO\n");}
;

lista_declaracoes: lista_declaracoes declaracao
        {printf("LISTA DE DECLARACOES RECONHECIDA\n");}
                | declaracao
        {printf("LISTA DE DECLARACOES RECONHECIDA\n");}
;

declaracao: declaracao_var
        {printf("DECLARACAO RECONHECIDA\n");}
          | declaracao_fun
        {printf("DECLARACAO RECONHECIDA\n");}
;


declaracao_var: tipo_especificador TK_ID TK_SEMI
        {printf("DECLARACAO VAR RECONHECIDA\n");}
              | tipo_especificador TK_ID TK_LBRACKET TK_NUM TK_RBRACKET TK_SEMI
        {printf("DECLARACAO VAR RECONHECIDA\n");}

;

tipo_especificador: TK_INT
        {printf("TIPO ESPECIFICADOR RECONHECIDO\n");}
                  | TK_VOID
        {printf("TIPO ESPECIFICADOR RECONHECIDO\n");}
;

declaracao_fun: tipo_especificador TK_ID TK_LPAREN params TK_RPAREN composto_decl
        {printf("DECLARACAO FUN RECONHECIDA\n");}
;

params: lista_params
        {printf("PARAMS RECONHECIDO\n");}
      | TK_VOID
        {printf("PARAMS RECONHECIDO\n");}
;

lista_params: lista_params TK_COMMA param
        {printf("LISTA PARAMS RECONHECIDO\n");}
            | param
        {printf("LISTA PARAMS RECONHECIDO\n");}
;

param: tipo_especificador TK_ID
        {printf("PARAM RECONHECIDO\n");}
     | tipo_especificador TK_ID TK_LBRACKET TK_RBRACKET
        {printf("PARAM RECONHECIDO\n");}
;

composto_decl: TK_LBRACE local_declaracoes lista_comando TK_RBRACE
        {printf("COMPOSTO DECL RECONHECIDO\n");}
;

local_declaracoes: local_declaracoes declaracao_var
        {printf("LOCAL DECLARACOES RECONHECIDO\n");}
                 | 
        {printf("LOCAL DECLARACOES RECONHECIDO\n");}
;

lista_comando: lista_comando comando
        {printf("LISTA COMANDO RECONHECIDO\n");}
             | 
        {printf("LISTA COMANDO RECONHECIDO\n");}
;

comando: expressao_decl
        {printf("COMANDO RECONHECIDO\n");}
       | selecao_decl
        {printf("COMANDO RECONHECIDO\n");}
       | iteracao_decl
        {printf("COMANDO RECONHECIDO\n");}
       | retorno_decl
        {printf("COMANDO RECONHECIDO\n");}
        | composto_decl
        {printf("COMANDO RECONHECIDO\n");}
;

expressao_decl: expressao TK_SEMI
        {printf("EXPRESSAO DECL RECONHECIDO\n");}
              | TK_SEMI
        {printf("EXPRESSAO DECL RECONHECIDO\n");}
;

selecao_decl: TK_IF TK_LPAREN expressao TK_RPAREN comando
        {printf("SELECAO DECL RECONHECIDO\n");}
            | TK_IF TK_LPAREN expressao TK_RPAREN comando TK_ELSE comando
        {printf("SELECAO DECL RECONHECIDO\n");}
;

iteracao_decl: TK_WHILE TK_LPAREN expressao TK_RPAREN comando
        {printf("ITERACAO DECL RECONHECIDO\n");}
;

retorno_decl: TK_RETURN TK_SEMI
        {printf("RETORNO DECL RECONHECIDO\n");}
            | TK_RETURN expressao TK_SEMI
        {printf("RETORNO DECL RECONHECIDO\n");}
;

expressao: var TK_ASSIGN expressao
        {printf("EXPRESSAO RECONHECIDO\n");}
         | simples_expressao
        {printf("EXPRESSAO RECONHECIDO\n");}
;

var: TK_ID
        {printf("VAR RECONHECIDO\n");}
   | TK_ID TK_LBRACKET expressao TK_RBRACKET
        {printf("VAR RECONHECIDO\n");}
;

simples_expressao: soma_expressao relacional soma_expressao
        {printf("SIMPLES EXPRESSAO RECONHECIDO\n");}    
                 | soma_expressao

        {printf("SIMPLES EXPRESSAO RECONHECIDO\n");}
;

relacional: TK_LT
        {printf("RELACIONAL RECONHECIDO\n");}
          | TK_LE
        {printf("RELACIONAL RECONHECIDO\n");}
          | TK_GT
        {printf("RELACIONAL RECONHECIDO\n");}
          | TK_GE
        {printf("RELACIONAL RECONHECIDO\n");}
          | TK_EQ
        {printf("RELACIONAL RECONHECIDO\n");}
          | TK_NE 
        {printf("RELACIONAL RECONHECIDO\n");}
;

soma_expressao: soma_expressao soma termo
        {printf("SOMA EXPRESSAO RECONHECIDO\n");}
              | termo
        {printf("SOMA EXPRESSAO RECONHECIDO\n");}
;

soma: TK_PLUS
        {printf("SOMA RECONHECIDO\n");}
    | TK_MINUS
        {printf("SOMA RECONHECIDO\n");}
;

termo: termo mult fator
        {printf("TERMO RECONHECIDO\n");}
     | fator
        {printf("TERMO RECONHECIDO\n");}
;

mult: TK_TIMES
        {printf("MULT RECONHECIDO\n");}
    | TK_OVER
        {printf("MULT RECONHECIDO\n");}
;

fator: TK_LPAREN expressao TK_RPAREN
        {printf("FATOR RECONHECIDO\n");}
     | var
        {printf("FATOR RECONHECIDO\n");}    
     | TK_NUM
        {printf("FATOR RECONHECIDO\n");}
     | chamada
        {printf("FATOR RECONHECIDO\n");}
;

chamada: TK_ID TK_LPAREN args TK_RPAREN
        {printf("CHAMADA RECONHECIDO\n");}
;

args: arg_lista
        {printf("ARGS RECONHECIDO\n");}
    |
        {printf("ARGS RECONHECIDO\n");}
;

arg_lista: arg_lista TK_COMMA expressao
        {printf("ARG LISTA RECONHECIDO\n");}
         | expressao
        {printf("ARG LISTA RECONHECIDO\n");}
;

%%

int parse(void) {
    //return yyparse();
    yyparse();
    return 0;
}

int yylex(void){

    int valor_token;
    int valor_convertido;

    valor_token = get_lexema();
    
    //mudar o valor do token para o valor que esta no parser
    if (valor_token == 0) {
        valor_convertido = TK_ELSE;
    } else if (valor_token == 1) {
        valor_convertido = TK_IF;
    } else if (valor_token == 2) {
        valor_convertido = TK_INT;
    } else if (valor_token == 3) {
        valor_convertido = TK_RETURN;
    } else if (valor_token == 4) {
        valor_convertido = TK_VOID;
    } else if (valor_token == 5) {
        valor_convertido = TK_WHILE;
    } else if (valor_token == 6) {
        valor_convertido = TK_ID;
    } else if (valor_token == 7) {
        valor_convertido = TK_NUM;
    } else if (valor_token == 8) {
        valor_convertido = TK_PLUS;
    } else if (valor_token == 9) {
        valor_convertido = TK_MINUS;
    } else if (valor_token == 10) {
        valor_convertido = TK_TIMES;
    } else if (valor_token == 11) {
        valor_convertido = TK_OVER;
    } else if (valor_token == 12) {
        valor_convertido = TK_LT;
    } else if (valor_token == 13) {
        valor_convertido = TK_LE;
    } else if (valor_token == 14) {
        valor_convertido = TK_GT;
    } else if (valor_token == 15) {
        valor_convertido = TK_GE;
    } else if (valor_token == 16) {
        valor_convertido = TK_EQ;
    } else if (valor_token == 17) {
        valor_convertido = TK_NE;
    } else if (valor_token == 18) {
        valor_convertido = TK_ASSIGN;
    } else if (valor_token == 19) {
        valor_convertido = TK_SEMI;
    } else if (valor_token == 20) {
        valor_convertido = TK_COMMA;
    } else if (valor_token == 21) {
        valor_convertido = TK_LPAREN;
    } else if (valor_token == 22) {
        valor_convertido = TK_RPAREN;
    } else if (valor_token == 23) {
        valor_convertido = TK_LBRACKET;
    } else if (valor_token == 24) {
        valor_convertido = TK_RBRACKET;
    } else if (valor_token == 25) {
        valor_convertido = TK_LBRACE;
    } else if (valor_token == 26) {
        valor_convertido = TK_RBRACE;
    }

    return valor_convertido;
}

int yyerror(char *s) {
    fprintf(stderr, "ERRO SINTÁTICO: %s LINHA: %d\n", s, linhaatual);
    return 0;
}
