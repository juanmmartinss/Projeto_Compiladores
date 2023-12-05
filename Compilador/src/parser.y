%{
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "global.h"
#include "parser_arvore.h"
#include "tabela_simbolos.h"

#define YYSTYPE pont_arv

int linhaatual;
const char *lexemaauxiliar = NULL;

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
            raiz = $1;
        }
        
;

lista_declaracoes: lista_declaracoes declaracao
        {   
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
            $$ = $1;
        }
;

declaracao: declaracao_var
        {   
            $$ = $1;
        }
        | declaracao_fun
        {   
            $$ = $1;
        }
;


declaracao_var: tipo_especificador TK_ID TK_SEMI
        {
            $$ = $1;

            //pega o tipo do no
            $$->tipo = (Tipo_no *)DECLARACAO;
            $$->linha = linhaatual;
            $$->tipodeclaracao = (Tipo_declaracao *)VARIAVELK;

            pont_arv aux = cria_no($2);

            lexemaauxiliar = peek(pilha);

            strcpy(aux->lexema, lexemaauxiliar);

            pop(pilha); //desempilha o id

            $$ = insere_filho($$, aux);

        }
        | tipo_especificador TK_ID TK_LBRACKET TK_NUM TK_RBRACKET TK_SEMI
        {
            $$ = $1;
            
            //pega o tipo do no
            $$->tipo = (Tipo_no *)DECLARACAO;
            $$->linha = linhaatual;
            $$->tipodeclaracao = (Tipo_declaracao *)VETORK;

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
            $$ = cria_no($1);
            strcpy($$->lexema, "INT");
            $$->linha = linhaatual;
            //printf("lexema: %s\n", $$->lexema);

        }
        | TK_VOID
        {
            $$ = cria_no($1);
            strcpy($$->lexema, "VOID");
            $$->linha = linhaatual;

        }
;

declaracao_fun: tipo_especificador id_fun TK_LPAREN params TK_RPAREN composto_decl
        {
            $$ = $1;
            insere_filho($$, $4);
            insere_filho($$, $2);
            insere_filho($2, $6);

            //pega o tipo do no
            $$->tipo = (Tipo_no *)DECLARACAO;
            $$->tipodeclaracao = (Tipo_declaracao *)FUNCAOK;
            //$$->linha = lex->linha;

        }
;

id_fun: TK_ID
        {
            $$ = cria_no($1);
            lexemaauxiliar = peek(pilha);
            strcpy($$->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id
            $$->linha = linhaatual;
        }

params: lista_params
        {
            $$ = $1;

        }
        | TK_VOID
        {
            $$ = cria_no($1);

            $$->tipo = (Tipo_no *)DECLARACAO;
            $$->linha = linhaatual;
            $$->tipodeclaracao = (Tipo_declaracao *)PARAMETROVOIDK;

            strcpy($$->lexema, "VOID");

        }
;

lista_params: lista_params TK_COMMA param
        {
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
            $$ = $1;
        }
;

param: tipo_especificador TK_ID
        {
            $$ = $1;

            //pega o tipo do no
            $$->tipo = (Tipo_no *)DECLARACAO;
            $$->linha = linhaatual;
            $$->tipodeclaracao = (Tipo_declaracao *)PARAMETROVARIAVELK;

            pont_arv aux = cria_no($2);

            lexemaauxiliar = peek(pilha);
            strcpy(aux->lexema, lexemaauxiliar);//pega o id
            //printf("string aux->lexema: %s\n", aux->lexema);
            pop(pilha); //desempilha o id

            $$ = insere_filho($$, aux);
        }
        | tipo_especificador TK_ID TK_LBRACKET TK_RBRACKET
        {
            $$ = $1;

            //pega o tipo do no
            $$->tipo = (Tipo_no *)DECLARACAO;
            $$->linha = linhaatual;
            $$->tipodeclaracao = (Tipo_declaracao *)PARAMETROVETORK;

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
            $$ = NULL;
        }
;

lista_comando: lista_comando comando
        {
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
            $$ = NULL;
        }
;

comando: expressao_decl
        {
            $$ = $1;
        }
        | selecao_decl
        {
            $$ = $1;
        }
        | iteracao_decl
        {
            $$ = $1;
        }
        | retorno_decl
        {
            $$ = $1;
        }
        | composto_decl
        {
            $$ = $1;
        }
;

expressao_decl: expressao TK_SEMI
        {
            $$ = $1;
        }
        | TK_SEMI
        {
            $$ = NULL;
        }
;

selecao_decl: TK_IF TK_LPAREN expressao TK_RPAREN comando fat_else
        {
            $$ = cria_no($1);

            strcpy($$->lexema, "IF");

            $$->tipo = (Tipo_no *)DECLARACAO;
            $$->linha = linhaatual;
            $$->tipodeclaracao = IFK;

            insere_filho($$, $3);
            insere_filho($$, $5);
            if($6 != NULL){
                insere_filho($$, $6);
            }
        }
;

fat_else: TK_ELSE comando
        {
            $$ = $2;
        }
        |
        {
            $$ = NULL;
        }

iteracao_decl: TK_WHILE TK_LPAREN expressao TK_RPAREN comando
        {
            $$ = cria_no($1);
            
            strcpy($$->lexema, "WHILE");

            $$->tipo = (Tipo_no *)DECLARACAO;
            $$->linha = linhaatual;
            $$->tipodeclaracao = (Tipo_declaracao *)WHILEK;

            insere_filho($$, $3);
            insere_filho($$, $5);

        }
;

retorno_decl: TK_RETURN TK_SEMI
        {
            $$ = cria_no($1);

            $$->tipo = (Tipo_no *)DECLARACAO;
            $$->linha = linhaatual;
            $$->tipodeclaracao = (Tipo_declaracao *)VOIDK;

            strcpy($$->lexema, "RETURNVOID");
        }
        | TK_RETURN expressao TK_SEMI
        {
            $$ = cria_no($1);

            $$->tipo = DECLARACAO;
            $$->linha = linhaatual;
            $$->tipodeclaracao = (Tipo_declaracao *)INTK;

            strcpy($$->lexema, "RETURNINT");
            insere_filho($$, $2);

        }
;

expressao: var TK_ASSIGN expressao
        {
            $$ = cria_no($2);

            strcpy($$->lexema, "=");
            
            $$->tipo = (Tipo_no *)EXPRESSAO;
            $$->linha = linhaatual;
            $$->tipoexpressao = (Tipo_expressao *)ATRIBUICAOK;

            

            insere_filho($$, $1);
            insere_filho($$, $3);

        }
        | simples_expressao
        {
            $$ = $1;
        }
;

var: TK_ID
        {
            $$ = cria_no($1);

            $$->tipo = (Tipo_no *)EXPRESSAO;
            //$$->tipodeclaracao = VARIAVEL;
            $$->linha = linhaatual;
            $$->tipoexpressao = (Tipo_expressao *)IDK;

            lexemaauxiliar = peek(pilha);
            //printf("lexema: %s\n", lexemaauxiliar);
            strcpy($$->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id


        }
        | TK_ID TK_LBRACKET expressao TK_RBRACKET
        {
            $$ = cria_no($1);

            $$->tipo = (Tipo_no *)EXPRESSAO;
            //$$->tipodeclaracao = VARIAVEL;
            $$->linha = linhaatual;
            $$->tipoexpressao = (Tipo_expressao *)VETORPARAMETROK;

            lexemaauxiliar = peek(pilha);
            strcpy($$->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id

            insere_filho($$, $3);

        }
;

simples_expressao: soma_expressao relacional soma_expressao
        {
            $$ = $2;

            $$->tipo = (Tipo_no *)EXPRESSAO;
            $$->linha = linhaatual;
            $$->tipoexpressao = (Tipo_expressao *)OPERADORRELACIONAL;

            insere_filho($$, $1);
            insere_filho($$, $3);

        }    
        | soma_expressao
        {
            $$ = $1;

        }
;

relacional: TK_LT
        {
            $$ = cria_no($1);
            strcpy($$->lexema, "<");

        }
        | TK_LE
        {
            $$ = cria_no($1);
            strcpy($$->lexema, "<=");

        }
        | TK_GT
        {
            $$ = cria_no($1);
            strcpy($$->lexema, ">");

        }
        | TK_GE
        {
            $$ = cria_no($1);
            strcpy($$->lexema, ">=");

        }
        | TK_EQ
        {
            $$ = cria_no($1);
            strcpy($$->lexema, "==");

        }
        | TK_NE 
        {
            $$ = cria_no($1);
            strcpy($$->lexema, "!=");

        }
;

soma_expressao: soma_expressao soma termo
        {
            $$ = $2;

            $$->tipo = (Tipo_no *)EXPRESSAO;
            $$->linha = linhaatual;
            $$->tipoexpressao = OPERANDO;

            insere_filho($$, $1);
            insere_filho($$, $3);

        }
        | termo
        {
            $$ = $1;
        
        }
;

soma: TK_PLUS
        {
            $$ = cria_no($1);
            strcpy($$->lexema, "+");

        }
        | TK_MINUS
        {
            $$ = cria_no($1);
            strcpy($$->lexema, "-");

        }
;

termo: termo mult fator
        {
            $$ = $2;

            $$->tipo = (Tipo_no *)EXPRESSAO;
            $$->linha = linhaatual;
            $$->tipoexpressao = OPERANDO;

            insere_filho($$, $1);
            insere_filho($$, $3);

        }
        | fator
        {
            $$ = $1;

        }
;

mult: TK_TIMES
        {
            $$ = cria_no($1);
            strcpy($$->lexema, "*");

        }
        | TK_OVER
        {
            $$ = cria_no($1);
            strcpy($$->lexema, "/");

        }
;

fator: TK_LPAREN expressao TK_RPAREN
        {
            $$ = $2;

        }
        | var
        {
            $$ = $1;

        }    
        | TK_NUM
        {
            $$ = cria_no($1);

            $$->tipo = (Tipo_no *)EXPRESSAO;
            $$->linha = linhaatual;
            $$->tipoexpressao = (Tipo_expressao *)CONSTANTE;

            lexemaauxiliar = peek(pilha);
            strcpy($$->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id

        }
        | chamada
        {
            $$ = $1;

        }
;

chamada: id_fun TK_LPAREN args TK_RPAREN
        {
            // $$ = cria_no($1);
            $$ = $1;

            $$->tipo = (Tipo_no *)EXPRESSAO;

            $$->linha = linhaatual;
            $$->tipoexpressao = (Tipo_expressao *)CHAMADAFUNCAO;


            insere_filho($$, $3);

        }
;

args: arg_lista
        {
            $$ = $1;

        }
        |
        {
            $$ = NULL;

        }
;

arg_lista: arg_lista TK_COMMA expressao
        {
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
    
    linhaatual = lex->linha;
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

    return valor_convertido;
}

int yyerror(char *s) {
    printf("-----------------ERRO SINTATICO-----------------\n");
    printf("LINHA: %d\n",lex->linha);
    fprintf(stderr, "ERRO SINTÁTICO: %s LINHA: %d\n", s, linhaatual);
    return 0;
}
