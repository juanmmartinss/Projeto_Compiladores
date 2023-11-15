
%{
/*Reconhecedor de bases numericas*/
#include <stdio.h>
#include <ctype.h>
#include "funcs.h"

%}

%token NUMBER

%%

command : exp { printf("Resultado: %d\n", $1); }
        ;
exp    : exp '+' term { $$ = $1 + $3; }
        | exp '-' term { $$ = $1 - $3; }
        |term { $$ = $1; }//termo
        ;

term   : term '*' factor { $$ = $1 * $3; }
        | factor { $$ = $1; }//fator
        ;

factor : NUMBER { $$ = $1; }
        | '(' exp ')' { $$ = $2; }
        ;

%%

int main()
{
        return yyparse();
}

int yylex(void){
        int c; 
        while((c = getchar()) == ' ' || c == '\t');

        if(isdigit(c)){
                ungetc(c, stdin);
                scanf("%d", &yylval);
                return NUMBER;
        }

        if (c == '\n'){
                return 0;
        }
        return (c);

}

int yyerror(char *s){
        fprintf(stderr, "%s\n", s);
        return 0;
}