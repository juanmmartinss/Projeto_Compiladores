#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum token{
    ELSE, IF, INT, RETURN, VOID, WHILE, ID, NUM, PLUS, MINUS, TIMES, OVER, LT, LE, GT, GE, EQ, NE, ASSIGN, SEMI,
     COMMA, LPAREN, RPAREN, LBRACKET, RBRACKET, LBRACE, RBRACE, MAIN, PRINTF, ERROR
}TokenType;

// typedef enum estado{
//     INICIO, INCOMENT, INNUM, INID, INATRIB, MENOR, MAIOR, DIFERENTE,
//     COMPARACAO, MAIORIGUAL, MENORIGUAL, WNC, WNC2, FIM, ERRO
// }DfaType;

typedef struct buffer{
    char *data;
    int size;
    int pos;
}Buffer;

typedef struct lex{
    int linha;
    TokenType token;
    int estado;
    char lexema[64];
}Lex;


Buffer *allocate_buffer(int size);// aloca a memoria do buffer
void deallocate_buffer(Buffer *buffer);//desaloca a memoria do buffer
char get_next_char(Buffer *buffer, FILE *arq, Lex *lex);//pega o proximo char do buffer
char* enche_buffer(Buffer *buffer, FILE *arq);
int pega_valor_para_matriz(char letra);
void Verifica_palavra_reservada(char *palavra, Lex *lex);
char* Pega_ID(int valor_letra, Lex *lex);
int Tabela_DFA(Lex *lex, char letra, Buffer *buffer);

