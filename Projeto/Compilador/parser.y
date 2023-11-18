%{
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int yylex();
int yyparse();
int yyerror(char *s);

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

%union {
    int intval;
    char* strval;
    Arvore* arvore;
}

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

%type <intval> TK_NUM
%type <strval> TK_ID
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

declaracao_var: tipo_especificador TK_ID TK_SEMI {$$ = cria_arvore(4, $1, cria_arvore(5, $2, NULL));}
              | tipo_especificador TK_ID TK_LBRACKET TK_NUM TK_RBRACKET TK_SEMI {$$ = cria_arvore(4, $1, cria_arvore(5, $2, cria_arvore(6, $4, NULL)));}
              ;

tipo_especificador: TK_INT {$$ = cria_arvore(7, NULL, NULL);}
                  | TK_VOID {$$ = cria_arvore(8, NULL, NULL);}
                  ;

declaracao_fun: tipo_especificador TK_ID TK_LPAREN params TK_RPAREN composto_decl {$$ = cria_arvore(9, cria_arvore(10, $1, cria_arvore(11, $2, NULL)), cria_arvore(12, $4, $6));}
              ;

params: lista_params {$$ = $1;}
      | TK_VOID {$$ = cria_arvore(13, NULL, NULL);}
      ;

lista_params: lista_params TK_COMMA param {$$ = cria_arvore(14, $1, $3);}
            | param {$$ = cria_arvore(14, $1, NULL);}
            ;

param: tipo_especificador TK_ID {$$ = cria_arvore(15, $1, cria_arvore(16, $2, NULL));}
     | tipo_especificador TK_ID TK_LBRACKET TK_RBRACKET {$$ = cria_arvore(15, $1, cria_arvore(16, $2, NULL));}
     ;

composto_decl: TK_LBRACE local_declaracoes lista_comando TK_RBRACE {$$ = cria_arvore(17, $2, $3);}
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

expressao_decl: expressao TK_SEMI {$$ = $1;}
              | TK_SEMI {$$ = NULL;}
              ;

selecao_decl: TK_IF TK_LPAREN expressao TK_RPAREN comando {$$ = cria_arvore(20, $3, $5);}
            | TK_IF TK_LPAREN expressao TK_RPAREN comando TK_ELSE comando {$$ = cria_arvore(21, $3, cria_arvore(22, $5, $7));}
            ;

iteracao_decl: TK_WHILE TK_LPAREN expressao TK_RPAREN comando {$$ = cria_arvore(23, $3, $5);}
             ;

retorno_decl: TK_RETURN TK_SEMI {$$ = cria_arvore(24, NULL, NULL);}
            | TK_RETURN expressao TK_SEMI {$$ = cria_arvore(24, $2, NULL);}
            ;

expressao: var TK_ASSIGN expressao {$$ = cria_arvore(25, $1, $3);}
         | simples_expressao {$$ = $1;}
         ;

var: TK_ID {$$ = cria_arvore(26, cria_arvore(27, $1, NULL), NULL);}
   | TK_ID TK_LBRACKET expressao TK_RBRACKET {$$ = cria_arvore(26, cria_arvore(27, $1, $3), NULL);}
   ;

simples_expressao: soma_expressao relacional soma_expressao {$$ = cria_arvore(28, $1, cria_arvore(29, $2, $3));}
                 | soma_expressao {$$ = $1;}
                 ;

relacional: TK_LT {$$ = cria_arvore(30, NULL, NULL);}
          | TK_LE {$$ = cria_arvore(31, NULL, NULL);}
          | TK_GT {$$ = cria_arvore(32, NULL, NULL);}
          | TK_GE {$$ = cria_arvore(33, NULL, NULL);}
          | TK_EQ {$$ = cria_arvore(34, NULL, NULL);}
          | TK_NE {$$ = cria_arvore(35, NULL, NULL);}
          ;

soma_expressao: soma_expressao soma termo {$$ = cria_arvore(36, $1, cria_arvore(37, $2, $3));}
              | termo {$$ = $1;}
              ;

soma: TK_PLUS {$$ = cria_arvore(38, NULL, NULL);}
    | TK_MINUS {$$ = cria_arvore(39, NULL, NULL);}
    ;

termo: termo mult fator {$$ = cria_arvore(40, $1, cria_arvore(41, $2, $3));}
     | fator {$$ = $1;}
     ;

mult: TK_TIMES {$$ = cria_arvore(42, NULL, NULL);}
    | TK_OVER {$$ = cria_arvore(43, NULL, NULL);}
    ;

fator: TK_LPAREN expressao TK_RPAREN {$$ = $2;}
     | var {$$ = $1;}
     | chamada {$$ = $1;}
     | TK_NUM {$$ = cria_arvore(44, NULL, cria_arvore(45, NULL, NULL));}
     ;

chamada: TK_ID TK_LPAREN args TK_RPAREN {$$ = cria_arvore(46, cria_arvore(47, $1, NULL), $3);}
       ;

args: arg_lista {$$ = $1;}
    | /* vazio */ {$$ = NULL;}
    ;

arg_lista: arg_lista TK_COMMA expressao {$$ = cria_arvore(48, $1, $3);}
         | expressao {$$ = cria_arvore(48, NULL, $1);}
         ;

%%

int main() {
    return yyparse();
}

int yylex(void){
    return getToken();
}

//yylex() é a função que retorna o token lido
int yyerror(char *s) {
    fprintf(stderr, "ERRO SINTÁTICO: %s LINHA: %d\n", s, lex->linha);
    return 0;
}
