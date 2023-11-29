%{
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "global.h"
#include "parser_arvore.h"

#define YYSTYPE pont_arv

int linhaatual;
const char *lexemaauxiliar;

//#define YYSTYPE pont_arv;
pont_arv parse(void);
int yylex();
int yyparse();
int yyerror(char *s);

pont_arv raiz;

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
        {   
            printf("PROGRAMA RECONHECIDO\n");
            raiz = $1;

            printf("\n");
            printf("-----------------ARVORE SINTATICA-----------------\n");
            printf("\n");

            imprime_arvore(raiz, 0);
        }
        
;

lista_declaracoes: lista_declaracoes declaracao
        {   
            printf("LISTA DE DECLARACOES RECONHECIDA\n");
            if($1 == NULL){
                $$ = $2;
            }
            else{
                $$ = $1;
                $$ = insere_irmao($$, $2);
            }
        }
        | declaracao
        {
            printf("LISTA DE DECLARACOES RECONHECIDA\n");
            $$ = $1;
        }
;

declaracao: declaracao_var
        {   
            printf("DECLARACAO RECONHECIDA\n");
            $$ = $1;
        }
        | declaracao_fun
        {   
            printf("DECLARACAO RECONHECIDA\n");
            $$ = $1;
        }
;


declaracao_var: tipo_especificador TK_ID TK_SEMI
        {
            printf("DECLARACAO VAR RECONHECIDA\n");
            $$ = $1;
            pont_arv aux = cria_no($2);

            lexemaauxiliar = peek(pilha);
            //printf("lexema: %s\n", lexemaauxiliar);
            strcpy(aux->lexema, lexemaauxiliar);
            //printf("string aux->lexema: %s\n", aux->lexema);
            pop(pilha); //desempilha o id

            $$ = insere_filho($$, aux);

        }
        | tipo_especificador TK_ID TK_LBRACKET TK_NUM TK_RBRACKET TK_SEMI
        {
            printf("DECLARACAO VAR RECONHECIDA\n");
            $$ = $1;
            pont_arv aux = cria_no($2);
            pont_arv aux2 = cria_no($4);

            lexemaauxiliar = peek(pilha);
            //printf("lexema: %s\n", lexemaauxiliar);
            strcpy(aux->lexema, lexemaauxiliar);
            //printf("string aux->lexema: %s\n", aux->lexema);
            pop(pilha); //desempilha o id

            lexemaauxiliar = peek(pilha);
            strcpy(aux2->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id
            // lexemaauxiliar = peek(pilha);
            // printf("lexema: %s\n", lexemaauxiliar);

            $$ = insere_filho($$, aux2);
            $$ = insere_filho($$, aux);
            


        }

;

tipo_especificador: TK_INT
        {
            printf("TIPO ESPECIFICADOR RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, "INT");
            //printf("lexema: %s\n", $$->lexema);

        }
        | TK_VOID
        {
            printf("TIPO ESPECIFICADOR RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, "VOID");

        }
;

declaracao_fun: tipo_especificador id_fun TK_LPAREN params TK_RPAREN composto_decl
        {
            printf("DECLARACAO FUN RECONHECIDA\n");
            $$ = $1;
            insere_filho($$, $4);
            insere_filho($$, $2);
            insere_filho($2, $6);
        }
;

id_fun: TK_ID
        {
            printf("ID FUN RECONHECIDO\n");
            $$ = cria_no($1);
            lexemaauxiliar = peek(pilha);
            strcpy($$->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id
        }

params: lista_params
        {
            printf("PARAMS RECONHECIDO\n");
            $$ = $1;

        }
        | TK_VOID
        {
            printf("PARAMS RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, "VOID");

        }
;

lista_params: lista_params TK_COMMA param
        {
            printf("LISTA PARAMS RECONHECIDO\n");
            if($1 == NULL){
                $$ = $3;
            }
            else{
                $$ = $1;
                insere_irmao($$, $3);
            }
        }
        | param
        {
            printf("LISTA PARAMS RECONHECIDO\n");
            $$ = $1;
        }
;

param: tipo_especificador TK_ID
        {
            printf("PARAM RECONHECIDO\n");
            $$ = $1;
            pont_arv aux = cria_no($2);

            lexemaauxiliar = peek(pilha);
            strcpy(aux->lexema, lexemaauxiliar);
            //printf("string aux->lexema: %s\n", aux->lexema);
            pop(pilha); //desempilha o id

            $$ = insere_filho($$, aux);
        }
        | tipo_especificador TK_ID TK_LBRACKET TK_RBRACKET
        {
            printf("PARAM RECONHECIDO\n");
            $$ = $1;
            pont_arv aux = cria_no($2);

            lexemaauxiliar = peek(pilha);
            strcpy(aux->lexema, lexemaauxiliar);
            //printf("string aux->lexema: %s\n", aux->lexema);
            pop(pilha); //desempilha o id

            $$ = insere_filho($$, aux);

        }
;

composto_decl: TK_LBRACE local_declaracoes lista_comando TK_RBRACE
        {
            printf("COMPOSTO DECL RECONHECIDO\n");
            if($2 == NULL){
                $$ = $3;
            }
            else{
                $$ = $2;
                insere_irmao($$, $3);
            }
        }
;

local_declaracoes: local_declaracoes declaracao_var
        {
            printf("LOCAL DECLARACOES RECONHECIDO\n");
            if($1 == NULL){
                $$ = $2;
            }
            else{
                $$ = $1;
                insere_irmao($$, $2);
            }
        }
        | 
        {
            printf("LOCAL DECLARACOES RECONHECIDO\n");
            $$ = NULL;
        }
;

lista_comando: lista_comando comando
        {
            printf("LISTA COMANDO RECONHECIDO\n");
            if($1 == NULL){
                $$ = $2;
            }
            else{
                $$ = $1;
                insere_irmao($$, $2);
            }
        }
        | 
        {
            printf("LISTA COMANDO RECONHECIDO\n");
            $$ = NULL;
        }
;

comando: expressao_decl
        {
            printf("COMANDO RECONHECIDO\n");
            $$ = $1;
        }
        | selecao_decl
        {
            printf("COMANDO RECONHECIDO\n");
            $$ = $1;
        }
        | iteracao_decl
        {
            printf("COMANDO RECONHECIDO\n");
            $$ = $1;
        }
        | retorno_decl
        {
            printf("COMANDO RECONHECIDO\n");
            $$ = $1;
        }
        | composto_decl
        {
            printf("COMANDO RECONHECIDO\n");
            $$ = $1;
        }
;

expressao_decl: expressao TK_SEMI
        {
            printf("EXPRESSAO DECL RECONHECIDO\n");
            $$ = $1;
        }
        | TK_SEMI
        {
            printf("EXPRESSAO DECL RECONHECIDO\n");
            $$ = NULL;
        }
;

selecao_decl: TK_IF TK_LPAREN expressao TK_RPAREN comando fat_else
        {
            printf("SELECAO DECL RECONHECIDO\n");
            $$ = cria_no($1);

            strcpy($$->lexema, "IF");

            insere_filho($$, $3);
            insere_filho($$, $5);
            if($6 != NULL){
                insere_filho($$, $6);
            }
        }
        // | TK_IF TK_LPAREN expressao TK_RPAREN comando TK_ELSE comando
        // {
        //     printf("SELECAO DECL RECONHECIDO\n");


        //     $$ = cria_no($1);

        //     strcpy($$->lexema, "IF");

        //     //$$ = cria_no($6);

        //     insere_filho($$, $3);
        //     insere_filho($$, $5);
        //     insere_filho($$, $7);

        //     // pont_arv aux = cria_no($7);
        //     // strcpy(aux->lexema, "ELSE");
        //     // insere_filho($$, aux);

        //     // insere_filho($1, cria_no($7));

        //     // //cria_no($6);
        //     // strcpy($$->lexema, "ELSE");
        //     // insere_filho($$, $6);


        // }
;

fat_else: TK_ELSE comando
        {
            printf("FAT ELSE RECONHECIDO\n");
            $$ = cria_no($1);

            strcpy($$->lexema, "ELSE");

            insere_filho($$, $2);
        }
        |
        {
            printf("FAT ELSE RECONHECIDO\n");
            $$ = NULL;
        }

iteracao_decl: TK_WHILE TK_LPAREN expressao TK_RPAREN comando
        {
            printf("ITERACAO DECL RECONHECIDO\n");
            $$ = cria_no($1);
            
            strcpy($$->lexema, "WHILE");

            insere_filho($$, $3);
            insere_filho($$, $5);

        }
;

retorno_decl: TK_RETURN TK_SEMI
        {
            printf("RETORNO DECL RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, "RETURNVOID");
        }
        | TK_RETURN expressao TK_SEMI
        {
            printf("RETORNO DECL RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, "RETURNINT");
            insere_filho($$, $2);

        }
;

expressao: var TK_ASSIGN expressao
        {
            printf("EXPRESSAO1 RECONHECIDO\n");
            $$ = cria_no($2);

            strcpy($$->lexema, "=");

            insere_filho($$, $1);
            insere_filho($$, $3);

        }
        | simples_expressao
        {
            printf("EXPRESSAO2 RECONHECIDO\n");
            $$ = $1;
        }
;

var: TK_ID
        {
            printf("VAR1 RECONHECIDO\n");
            $$ = cria_no($1);
            lexemaauxiliar = peek(pilha);
            //printf("lexema: %s\n", lexemaauxiliar);
            strcpy($$->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id


        }
        | TK_ID TK_LBRACKET expressao TK_RBRACKET
        {
            printf("VAR2 RECONHECIDO\n");
            $$ = cria_no($1);

            lexemaauxiliar = peek(pilha);
            strcpy($$->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id

            insere_filho($$, $3);

        }
;

simples_expressao: soma_expressao relacional soma_expressao
        {
            printf("SIMPLES EXPRESSAO1 RECONHECIDO\n");
            $$ = $2;
            insere_filho($$, $1);
            insere_filho($$, $3);

        }    
        | soma_expressao
        {
            printf("SIMPLES EXPRESSAO2 RECONHECIDO\n");
            $$ = $1;

        }
;

relacional: TK_LT
        {
            printf("RELACIONAL RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, "<");

        }
        | TK_LE
        {
            printf("RELACIONAL RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, "<=");

        }
        | TK_GT
        {
            printf("RELACIONAL RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, ">");

        }
        | TK_GE
        {
            printf("RELACIONAL RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, ">=");

        }
        | TK_EQ
        {
            printf("RELACIONAL RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, "==");

        }
        | TK_NE 
        {
            printf("RELACIONAL RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, "!=");

        }
;

soma_expressao: soma_expressao soma termo
        {
            printf("SOMA EXPRESSAO1 RECONHECIDO\n");
            $$ = $2;
            insere_filho($$, $1);
            insere_filho($$, $3);

        }
        | termo
        {
            printf("SOMA EXPRESSAO2 RECONHECIDO\n");
            $$ = $1;
        
        }
;

soma: TK_PLUS
        {
            printf("SOMA RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, "+");

        }
        | TK_MINUS
        {
            printf("SOMA RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, "-");

        }
;

termo: termo mult fator
        {
            printf("TERMO1 RECONHECIDO\n");
            $$ = $2;
            insere_filho($$, $1);
            insere_filho($$, $3);

        }
        | fator
        {
            printf("TERMO2 RECONHECIDO\n");
            $$ = $1;

        }
;

mult: TK_TIMES
        {
            printf("MULT RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, "*");

        }
        | TK_OVER
        {
            printf("MULT RECONHECIDO\n");
            $$ = cria_no($1);
            strcpy($$->lexema, "/");

        }
;

fator: TK_LPAREN expressao TK_RPAREN
        {
            printf("FATOR1 RECONHECIDO\n");
            $$ = $2;

        }
        | var
        {
            printf("FATOR2 RECONHECIDO\n");
            $$ = $1;

        }    
        | TK_NUM
        {
            printf("FATOR3 RECONHECIDO\n");
            $$ = cria_no($1);
            lexemaauxiliar = peek(pilha);
            strcpy($$->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id

        }
        | chamada
        {
            printf("FATOR4 RECONHECIDO\n");
            $$ = $1;

        }
;

chamada: id_fun TK_LPAREN args TK_RPAREN
        {
            printf("CHAMADA RECONHECIDO\n");
            // $$ = cria_no($1);
            $$ = $1;

            // lexemaauxiliar = peek(pilha);
    
            // strcpy($$->lexema, lexemaauxiliar);
            // pop(pilha); //desempilha o id

            insere_filho($$, $3);

        }
;

args: arg_lista
        {
            printf("ARGS RECONHECIDO\n");
            $$ = $1;

        }
        |
        {
            printf("ARGS RECONHECIDO\n");
            $$ = NULL;

        }
;

arg_lista: arg_lista TK_COMMA expressao
        {
            printf("ARG LISTA RECONHECIDO\n");
            if($1 == NULL){
                $$ = $3;
            }
            else{
                $$ = $1;
                insere_irmao($$, $3);
            }

        }
        | expressao
        {
            printf("ARG LISTA RECONHECIDO\n");
            $$ = $1;
            
        }
;

%%

pont_arv parse(void) {
    //return yyparse();
    yyparse();
    //printa a raiz da arvore
    return raiz;
}

int yylex(void){

    int valor_token = 0;
    int valor_convertido = 0;

    valor_token = get_lexema();
    
    //mudar o valor do token para o valor que esta no parser
    if(valor_token == -1){
        valor_convertido = YYEOF;
        //imprime_arvore(raiz, 0);
    }
    else if (valor_token == 0) {
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

    //yylval = 

    return valor_convertido;
}

int yyerror(char *s) {
    printf("-----------------ERRO SINTATICO-----------------\n");
    printf("LINHA: %d\n",lex->linha);
    fprintf(stderr, "ERRO SINTÁTICO: %s LINHA: %d\n", s, lex->linha);
    return 0;
}
