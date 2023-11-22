%{
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "global.h"
#include "parser.h"

extern int linhaatual;

int yylex();
int yyparse();
int yyerror(char *s);

TokenType getToken(int argc, char *argv[]);

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





int main() {
    return yyparse();
}

int yylex(void){
    return getToken();
}

int yyerror(char *s) {
    fprintf(stderr, "ERRO SINTÁTICO: %s LINHA: %d\n", s, linhaatual);
    return 0;
}
