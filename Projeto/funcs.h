#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum token{
    ELSE, IF, INT, RETURN, VOID, WHILE, ID, NUM
}TokenType;

typedef enum estado{
    INICIO, INCOMENT, INNUM, INID, INATRIB, MENOR, MAIOR, DIFERENTE,
    COMPARACAO, MAIORIGUAL, MENORIGUAL, WNC, WNC2, FIM, ERRO
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

int matriz_dfa[13][19] = {
                         {2, 3, 14, 14, 14, 14, 14, 14, 14, 14, 14, 4, 10, 7, 8, 9, 14, 14, 15},
                         {2, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14},
                         {14, 3, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14},
                         {15, 14, 5, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 14},
                         {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 5, 5, 5, 5, 5, 5, 5},
                         {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 5, 5, 5, 5, 5, 5, 5},
                         {15, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 13, 15, 15, 15, 15, 15, 14},
                         {15, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 15, 15, 15, 15, 15, 14},
                         {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 14, 15, 15, 15, 15, 15, 15},
                         {14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 11, 15, 15, 15, 15, 15, 14},
                         {14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14},
                         {15, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 14},
                         {15, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 14},
                         };

Buffer *allocate_buffer(int size);// aloca a memoria do buffer
void deallocate_buffer(Buffer *buffer);//desaloca a memoria do buffer
char get_next_char(Buffer *buffer, FILE *arq, Lex *lex);//pega o proximo char do buffer
char* enche_buffer(Buffer *buffer, FILE *arq);
void Verifica_palavra_reservada(char *palavra, Lex *lex);
char* Pega_ID(int valor_letra, Lex *lex);
void Tabela_DFA(Lex *lex, char letra, Buffer *buffer);


