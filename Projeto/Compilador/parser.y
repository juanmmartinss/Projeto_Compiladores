%{
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int yylex();

typedef struct Arvore {
    int info;
    struct Arvore *esq;
    struct Arvore *dir;
} Arvore;

Arvore *cria_arvore(int info, Arvore *esq, Arvore *dir) {
    Arvore *No = (Arvore *)malloc(sizeof(Arvore));
    No->info = info;
    No->esq = esq;
    No->dir = dir;
    return No;
}

void imprime_arvore(Arvore *No) {
    if (No != NULL) {
        printf("<");
        imprime_arvore(No->esq);
        printf("%d", No->info);
        imprime_arvore(No->dir);
        printf(">");
    } else {
        printf("<>");
    }
}

%}

%token ELSE
%token IF
%token INT
%token RETURN
%token VOID
%token WHILE
%token ID
%token NUM
%token PLUS
%token MINUS
%token TIMES
%token OVER
%token LT
%token LE
%token GT
%token GE
%token EQ
%token NE
%token ASSIGN
%token SEMI
%token COMMA
%token LPAREN
%token RPAREN
%token LBRACKET
%token RBRACKET
%token LBRACE
%token RBRACE
%token MAIN
%token PRINTF

%union {
    int intval;
    char* strval;
    Arvore* arvore;
}

%type <intval> NUM
%type <strval> ID
%type <arvore> programa lista_declaracoes declaracao declaracao_var tipo_especificador
            declaracao_fun params lista_params param composto_decl local_declaracoes
            lista_comando comando expressao_decl selecao_decl iteracao_decl retorno_decl
            expressao var simples_expressao relacional soma_expressao soma termo
            mult fator chamada args arg_lista

%%

//regras implementadas seguindo o arquivo disponibilizado no classroom

programa: lista_declaracoes {$$ = cria_arvore(1, $1, NULL);}
        ;

lista_declaracoes: lista_declaracoes declaracao {$$ = cria_arvore(2, $1, $2);}
                 | declaracao {$$ = cria_arvore(3, $1, NULL);}
                 ;

declaracao: declaracao_var {$$ = $1;}
          | declaracao_fun {$$ = $1;}
          ;

declaracao_var: tipo_especificador ID SEMI {$$ = cria_arvore(4, $1, cria_arvore(5, $2, NULL));}
              | tipo_especificador ID LBRACKET NUM RBRACKET SEMI {$$ = cria_arvore(4, $1, cria_arvore(5, $2, cria_arvore(6, $4, NULL)));}
              ;

tipo_especificador: INT {$$ = cria_arvore(7, NULL, NULL);}
                  | VOID {$$ = cria_arvore(8, NULL, NULL);}
                  ;

declaracao_fun: tipo_especificador ID LPAREN params RPAREN composto_decl {$$ = cria_arvore(9, cria_arvore(10, $1, cria_arvore(11, $2, NULL)), cria_arvore(12, $4, $6));}
              ;

params: lista_params {$$ = $1;}
      | VOID {$$ = cria_arvore(13, NULL, NULL);}
      ;

lista_params: lista_params COMMA param {$$ = cria_arvore(14, $1, $3);}
            | param {$$ = cria_arvore(14, $1, NULL);}
            ;

param: tipo_especificador ID {$$ = cria_arvore(15, $1, cria_arvore(16, $2, NULL));}
     | tipo_especificador ID LBRACKET RBRACKET {$$ = cria_arvore(15, $1, cria_arvore(16, $2, NULL));}
     ;

composto_decl: LBRACE local_declaracoes lista_comando RBRACE {$$ = cria_arvore(17, $2, $3);}
             ;

local_declaracoes: local_declaracoes declaracao_var {$$ = cria_arvore(18, $1, $2);}
                 | /* vazio */ {$$ = NULL;}
                 ;

lista_comando: lista_comando comando {$$ = cria_arvore(19, $1, $2);}
             | /* vazio */ {$$ = NULL;}
             ;

comando: expressao_decl {$$ = $1;}
       | composto_decl {$$ = $1;}
       | selecao_decl {$$ = $1;}
       | iteracao_decl {$$ = $1;}
       | retorno_decl {$$ = $1;}
       ;

expressao_decl: expressao SEMI {$$ = $1;}
              | SEMI {$$ = NULL;}
              ;

selecao_decl: IF LPAREN expressao RPAREN comando {$$ = cria_arvore(20, $3, $5);}
            | IF LPAREN expressao RPAREN comando ELSE comando {$$ = cria_arvore(21, $3, cria_arvore(22, $5, $7));}
            ;

iteracao_decl: WHILE LPAREN expressao RPAREN comando {$$ = cria_arvore(23, $3, $5);}
             ;

retorno_decl: RETURN SEMI {$$ = cria_arvore(24, NULL, NULL);}
            | RETURN expressao SEMI {$$ = cria_arvore(24, $2, NULL);}
            ;

expressao: var ASSIGN expressao {$$ = cria_arvore(25, $1, $3);}
         | simples_expressao {$$ = $1;}
         ;

var: ID {$$ = cria_arvore(26, cria_arvore(27, $1, NULL), NULL);}
   | ID LBRACKET expressao RBRACKET {$$ = cria_arvore(26, cria_arvore(27, $1, $3), NULL);}
   ;

simples_expressao: soma_expressao relacional soma_expressao {$$ = cria_arvore(28, $1, cria_arvore(29, $2, $3));}
                 | soma_expressao {$$ = $1;}
                 ;

relacional: LT {$$ = cria_arvore(30, NULL, NULL);}
          | LE {$$ = cria_arvore(31, NULL, NULL);}
          | GT {$$ = cria_arvore(32, NULL, NULL);}
          | GE {$$ = cria_arvore(33, NULL, NULL);}
          | EQ {$$ = cria_arvore(34, NULL, NULL);}
          | NE {$$ = cria_arvore(35, NULL, NULL);}
          ;

soma_expressao: soma_expressao soma termo {$$ = cria_arvore(36, $1, cria_arvore(37, $2, $3));}
              | termo {$$ = $1;}
              ;

soma: PLUS {$$ = cria_arvore(38, NULL, NULL);}
    | MINUS {$$ = cria_arvore(39, NULL, NULL);}
    ;

termo: termo mult fator {$$ = cria_arvore(40, $1, cria_arvore(41, $2, $3));}
     | fator {$$ = $1;}
     ;

mult: TIMES {$$ = cria_arvore(42, NULL, NULL);}
    | OVER {$$ = cria_arvore(43, NULL, NULL);}
    ;

fator: LPAREN expressao RPAREN {$$ = $2;}
     | var {$$ = $1;}
     | chamada {$$ = $1;}
     | NUM {$$ = cria_arvore(44, NULL, cria_arvore(45, NULL, NULL));}
     ;

chamada: ID LPAREN args RPAREN {$$ = cria_arvore(46, cria_arvore(47, $1, NULL), $3);}
       ;

args: arg_lista {$$ = $1;}
    | /* vazio */ {$$ = NULL;}
    ;

arg_lista: arg_lista COMMA expressao {$$ = cria_arvore(48, $1, $3);}
         | expressao {$$ = cria_arvore(48, NULL, $1);}
         ;

%%

int main() {
    return yyparse();
}

//yylex() é a função que retorna o token lido
int yyerror(char *s) {
    fprintf(stderr, "ERRO SINTÁTICO: %s LINHA: %d\n", s, num_linha_atual);
    return 0;
}
