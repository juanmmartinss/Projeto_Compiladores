%{
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "global.h"
//#include "parser.h"

int linhaatual;



//#define YYSTYPE pont_arv;

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
;

lista_declaracoes: lista_declaracoes declaracao
                 | declaracao
;

declaracao: declaracao_var
          | declaracao_fun
;

declaracao_var: tipo_especificador TK_ID TK_SEMI
              | tipo_especificador TK_ID TK_LBRACKET TK_NUM TK_RBRACKET TK_SEMI

;

tipo_especificador: TK_INT
                  | TK_VOID
;

declaracao_fun: tipo_especificador TK_ID TK_LPAREN params TK_RPAREN composto_decl
;

params: lista_params
      | TK_VOID
;

lista_params: lista_params TK_COMMA param
            | param
;

param: tipo_especificador TK_ID
     | tipo_especificador TK_ID TK_LBRACKET TK_RBRACKET
;

composto_decl: TK_LBRACE local_declaracoes lista_comando TK_RBRACE
;

local_declaracoes: local_declaracoes declaracao_var
                 | declaracao_var
;

lista_comando: lista_comando comando
             | comando
;

comando: TK_LBRACE lista_comando TK_RBRACE
       | expressao_decl
       | selecao_decl
       | iteracao_decl
       | retorno_decl
;

expressao_decl: expressao TK_SEMI
              | TK_SEMI
;

selecao_decl: TK_IF TK_LPAREN expressao TK_RPAREN comando
            | TK_IF TK_LPAREN expressao TK_RPAREN comando TK_ELSE comando
;

iteracao_decl: TK_WHILE TK_LPAREN expressao TK_RPAREN comando
;

retorno_decl: TK_RETURN TK_SEMI
            | TK_RETURN expressao TK_SEMI
;

expressao: var TK_ASSIGN expressao
         | simples_expressao
;

var: TK_ID
   | TK_ID TK_LBRACKET expressao TK_RBRACKET
;

simples_expressao: soma_expressao
                 | soma_expressao relacional soma_expressao
;

relacional: TK_LT
          | TK_LE
          | TK_GT
          | TK_GE
          | TK_EQ
          | TK_NE
;

soma_expressao: soma_expressao soma termo
              | termo
;

soma: TK_PLUS
    | TK_MINUS
;

termo: termo mult fator
     | fator
;

mult: TK_TIMES
    | TK_OVER
;

fator: TK_LPAREN expressao TK_RPAREN
     | var
     | TK_NUM
     | chamada
;

chamada: TK_ID TK_LPAREN args TK_RPAREN
;

args: arg_lista
    | TK_VOID
;

arg_lista: arg_lista TK_COMMA expressao
         | expressao
;

%%

int parse(void) {
    //return yyparse();
    yyparse();
    return 0;
}

int yylex(void){
    //return
    return get_lexema();
}

int yyerror(char *s) {
    fprintf(stderr, "ERRO SINTÁTICO: %s LINHA: %d\n", s, linhaatual);
    return 0;
}
