#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define HASH_SIZE 28

typedef enum token{
    ELSE, IF, INT, RETURN, VOID, WHILE, ID, NUM, PLUS, MINUS, TIMES, OVER, LT, LE, GT, GE, EQ, NE, ASSIGN, SEMI,
     COMMA, LPAREN, RPAREN, LBRACKET, RBRACKET, LBRACE, RBRACE, MAIN, PRINTF, ERROR
}TokenType;

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
    int aux;
}Lex;

typedef struct hash{
    char *palavra;
    TokenType token;
    struct hash *prox;
}PalavraReservada;

typedef struct no {
    char *palavra;
    TokenType token;
    struct no *esquerda;
    struct no *direita;
} No;

typedef struct pilha{
    int topo;
    char itens[100][64];
}Pilha;


//static No *raiz = NULL; // Árvore binária de busca balanceada

int get_lexema();

Buffer *allocate_buffer(int size);// aloca a memoria do buffer
void deallocate_buffer(Buffer *buffer);//desaloca a memoria do buffer
char get_next_char(Buffer *buffer, FILE *arq, Lex *lex);//pega o proximo char do buffer
char* enche_buffer(Buffer *buffer, FILE *arq);
int pega_valor_para_matriz(char letra);
void Verifica_palavra_reservada(char *palavra, Lex *lex);
void Pega_ID(int valor_letra, Lex *lex, char *pega_carac);
int Tabela_DFA(Lex *lex, char letra, Buffer *buffer);
No* novo_no(char *palavra, TokenType token);
No* insere_no(No *raiz, char *palavra, TokenType token);
No* busca_no(No *raiz, char *palavra);
void libera_arvore(No *raiz);
void chama_desaloca_arvore();

TokenType getToken(int argc, char *argv[]);

void initialize(Pilha *stack);
int isEmpty(Pilha *stack) ;
int isFull(Pilha *stack);
void push(Pilha *stack, const char *word);
void pop(Pilha *stack);
const char *peek(Pilha *stack);
void liberar_pilha(Pilha *stack);

void teste(Lex *lex, char *pega_carac, Buffer *buffer, FILE *input_file, char letra, char c, int linha_atual, int controle);

// void printa_arvore(No *raiz, int nivel);