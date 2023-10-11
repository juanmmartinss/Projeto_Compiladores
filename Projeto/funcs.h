#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum token{
    ELSE, IF, INT, RETURN, VOID, WHILE, ID, NUM
}TokenType;

typedef enum estado{
    INICIO, INCOMENT, INNUM, INID, INATRIB, FIM, ERRO
}DfaType;

typedef struct buffer{
    char *data;
    int size;
    int pos;
}Buffer;

typedef struct lex{
    int linha;
    TokenType token;
    DfaType estado;
    char lexema[64];
    int Aux;
}Lex;


Buffer *allocate_buffer(int size);// aloca a memoria do buffer
void deallocate_buffer(Buffer *buffer);//desaloca a memoria do buffer
char get_next_char(Buffer *buffer, FILE *arq, Lex *lex);//pega o proximo char do buffer
char* enche_buffer(Buffer *buffer, FILE *arq);
void Verifica_palavra_reservada(char *palavra, Lex *lex);
char* Pega_ID(int valor_letra, Lex *lex);
void cases_aninhados_dfa(Lex *lex, char letra, Buffer *buffer);


