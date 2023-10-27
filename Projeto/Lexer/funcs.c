#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


int matriz_dfa[16][21] = {
                         {2, 3, 16, 16, 16, 16, 16, 16, 16, 16, 16, 4, 12, 8, 10, 9, 16, 16, 16, 1, 18},
                         {2, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18},
                         {17, 3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18},
                         {17, 17, 5, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 18},
                         {5, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
                         {5, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5},
                         {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18},
                         {17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 15, 18, 18, 18, 18, 18, 18, 17, 18},
                         {18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 12, 18, 18, 18, 18, 18, 18, 18, 18},
                         {17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 14, 18, 18, 18, 18, 18, 18, 17, 18},
                         {18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 18, 18, 18, 18, 18, 18, 17, 18},
                         {17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 13, 18, 18, 18, 18, 18, 18, 17, 18},
                         {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18},
                         {18, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 18},
                         {18, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 18},
                         {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17},
                         };


Buffer *allocate_buffer(int size) {
    Buffer *buffer = (Buffer*)malloc(sizeof(Buffer));
    buffer->data = (char*)malloc(sizeof(char) * size);
    if (buffer->data == NULL) {
        fprintf(stderr, "Failed to allocate buffer\n");
        exit(1);
    }
    buffer->size = size; // Definir o tamanho do buffer corretamente
    return buffer;
}

void deallocate_buffer(Buffer *buffer) {
    if (buffer != NULL) { // Verificar se o buffer não é nulo antes de liberar
        free(buffer->data);
        free(buffer);// Liberar o buffer
    }
}

char* enche_buffer(Buffer *buffer, FILE *arq) {
    memset(buffer->data, '\0', buffer->size);
    char *str = fgets(buffer->data, buffer->size, arq);

    return str;
}


char get_next_char(Buffer *buffer, FILE *arq, Lex *lex) {
    if (buffer->pos >= buffer->size) {
        if (enche_buffer(buffer, arq) == NULL) {
            return '\0';
        }
        buffer->pos = 0;
    }
    else if(buffer->data[buffer->pos] == '\0'){
        if (enche_buffer(buffer, arq) == NULL) {
            return '\0';
        }
        lex->linha++;
        buffer->pos = 0;
    }
    
    return buffer->data[buffer->pos++];

}


int pega_valor_para_matriz(char letra){
  int valor;

  if (isdigit(letra) != 0){
    valor = 1;
  }
  else if (isalpha(letra) != 0){
    valor = 0;
  }
  else if (letra == '*'){
    valor = 2;
  }
  else if (letra == '+'){
    valor = 3;
  }
  else if (letra == '-'){
    valor = 4;
  }
  else if (letra == ','){
    valor = 5;
  }
  else if (letra == '{'){
    valor = 6;
  }
  else if (letra == '}'){
    valor = 7;
  }
  else if (letra == '('){
    valor = 8;
  }
  else if (letra == ')'){
    valor = 9;
  }
  else if (letra == ';'){
    valor = 10;
  }
  else if (letra == '/'){
    valor = 11;
  }
  else if (letra == '='){
    valor = 12;
  }
  else if (letra == '<'){
    valor = 13;
  }
  else if (letra == '>'){
    valor = 14;
  }
  else if (letra == '!'){
    valor = 15;
  }
  else if (letra == '['){
    valor = 16;
  }
  else if (letra == ']'){
    valor = 17;
  }
  else if (letra == '.'){
    valor = 18;
  }
  else if (letra == ' ' || letra == '\t' || letra == '\n'){
    valor = 19;
  }
  else{
    valor = 20;
  }

  return valor;
}

int Tabela_DFA(Lex *lex, char letra, Buffer *buffer) {
    int estado;
    int valor;
    int isSpecialChar = 0; // flag para verificar se o caracter é especial, para não armazenar no buffer
    //lex->aux = 0;

    if (lex->estado != 17 && lex->estado != 18) {
        if (lex->estado != 0) {//para se adequar a matriz, pois a martiz começa em 0 mas a logica esta para começar em 1
            estado = lex->estado - 1;
        } else {
            estado = lex->estado;
        }

        valor = pega_valor_para_matriz(letra);

        lex->estado = matriz_dfa[estado][valor];
    }

    //printf("matriz[%d][%d] = %d\n", estado, valor, lex->estado);
    

    if (lex->estado == 17) { // Aceita o estado 17, que é o estado final
        isSpecialChar = 1;
    }

    if (lex->estado == 18) {//se o estado for 18, o lexema é um erro
        lex->aux = 1;
        return 1;
    }

    if (!isSpecialChar) {// se não for um caracter especial, armazena no buffer
        buffer->data[buffer->pos - 1] = letra; // Armazena o caracter no buffer, na posição atual
    } else {
        buffer->pos--; // Move o ponteiro do buffer para a posição anterior, para não armazenar o caracter especial
    }

    return isSpecialChar;
}

No* novo_no(char *palavra, TokenType token) {
    No *novo = (No*) malloc(sizeof(No));
    novo->palavra = palavra;
    novo->token = token;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* insere_no(No *raiz, char *palavra, TokenType token) {
    if (raiz == NULL) {
        return novo_no(palavra, token);
    }
    int cmp = strcmp(palavra, raiz->palavra);
    if (cmp < 0) {
        raiz->esquerda = insere_no(raiz->esquerda, palavra, token);
    } else if (cmp > 0) {
        raiz->direita = insere_no(raiz->direita, palavra, token);
    } else {
        // A palavra já existe na árvore
        free(palavra);
    }
    return raiz;
}

No* busca_no(No *raiz, char *palavra) {
    if (raiz == NULL || strcmp(palavra, raiz->palavra) == 0) {
        return raiz;
    }
    if (strcmp(palavra, raiz->palavra) < 0) {
        return busca_no(raiz->esquerda, palavra);
    } else {
        return busca_no(raiz->direita, palavra);
    }
}

void libera_arvore(No *raiz) {
    if (raiz != NULL) {
        libera_arvore(raiz->esquerda);
        libera_arvore(raiz->direita);
        free(raiz->palavra);
        free(raiz);
    }
}

// void imprimir_arvore(No *raiz, int tab)
// {
//     if (raiz != NULL)
//     {
//         imprimir_arvore(raiz->esquerda, tab + 1);
//         for (int i = 0; i < tab; i++)
//         {
//             printf("\t");
//         }
//         printf("%s\n", raiz->palavra);
//         imprimir_arvore(raiz->direita, tab + 1);
//     }
// }

void Verifica_palavra_reservada(char *palavra, Lex *lex) {
    static No *raiz = NULL; // Árvore binária de busca balanceada
    if (raiz == NULL) {
        raiz = novo_no("else", ELSE);
        // Inicializa a árvore binária de busca com as palavras reservadas
        raiz = insere_no(raiz, "if", IF);
        raiz = insere_no(raiz, "int", INT);
        raiz = insere_no(raiz, "return", RETURN);
        raiz = insere_no(raiz, "void", VOID);
        raiz = insere_no(raiz, "while", WHILE);
        raiz = insere_no(raiz, "num", NUM);
        //plus
        raiz = insere_no(raiz, "+", PLUS);
        //minus
        raiz = insere_no(raiz, "-", MINUS);
        //times
        raiz = insere_no(raiz, "*", TIMES);
        //over
        raiz = insere_no(raiz, "/", OVER);
        //lt
        raiz = insere_no(raiz, "<", LT);
        //le
        raiz = insere_no(raiz, "<=", LE);
        //gt
        raiz = insere_no(raiz, ">", GT);
        //ge
        raiz = insere_no(raiz, ">=", GE);
        //eq
        raiz = insere_no(raiz, "==", EQ);
        //ne
        raiz = insere_no(raiz, "!=", NE);
        //assign
        raiz = insere_no(raiz, "=", ASSIGN);
        //semi
        raiz = insere_no(raiz, ";", SEMI);
        //comma
        raiz = insere_no(raiz, ",", COMMA);
        //lparen
        raiz = insere_no(raiz, "(", LPAREN);
        //rparen
        raiz = insere_no(raiz, ")", RPAREN);
        //lbracket
        raiz = insere_no(raiz, "[", LBRACKET);
        //rbracket
        raiz = insere_no(raiz, "]", RBRACKET);
        //lbrace
        raiz = insere_no(raiz, "{", LBRACE);
        //rbrace
        raiz = insere_no(raiz, "}", RBRACE);
        
        raiz = insere_no(raiz, "main", MAIN);
        raiz = insere_no(raiz, "printf", PRINTF);

        
    }



    No *no = busca_no(raiz, palavra);
    if (no != NULL) {
        lex->token = no->token;
    } else {
        lex->token = ID;
    }

    imprimir_arvore(raiz, 1);
}

 
char* Pega_ID(int valor_letra, Lex *lex){

  char *pega_carac = (char*)malloc(sizeof(char)*64);

  if (valor_letra == 0){
    pega_carac = "ELSE";
    return pega_carac;
  }
  else if (valor_letra == 1){
    pega_carac = "IF";
    return pega_carac;
  }
  else if (valor_letra == 2){
    pega_carac = "INT";
    return pega_carac;
  }
  else if (valor_letra == 3){
    pega_carac = "RETURN";
    return pega_carac;
  }
  else if (valor_letra == 4){
    pega_carac = "VOID";
    return pega_carac;
  }
  else if (valor_letra == 5){
    pega_carac = "WHILE";
    return pega_carac;
  }
  else if (valor_letra == 7){
    pega_carac = "NUM";
    return pega_carac;
  }
  else if (valor_letra == 8){
    pega_carac = "PLUS";
    return pega_carac;
  }
  else if (valor_letra == 9){
    pega_carac = "MINUS";
    return pega_carac;
  }
  else if (valor_letra == 10){
    pega_carac = "TIMES";
    return pega_carac;
  }
  else if (valor_letra == 11){
    pega_carac = "OVER";
    return pega_carac;
  }
  else if (valor_letra == 12){
    pega_carac = "LT";
    return pega_carac;
  }
  else if (valor_letra == 13){
    pega_carac = "LE";
    return pega_carac;
  }
  else if (valor_letra == 14){
    pega_carac = "GT";
    return pega_carac;
  }
  else if (valor_letra == 15){
    pega_carac = "GE";
    return pega_carac;
  }
  else if (valor_letra == 16){
    pega_carac = "EQ";
    return pega_carac;
  }
  else if (valor_letra == 17){
    pega_carac = "NE";
    return pega_carac;
  }
  else if (valor_letra == 18){
    pega_carac = "ASSIGN";
    return pega_carac;
  }
  else if (valor_letra == 19){
    pega_carac = "SEMI";
    return pega_carac;
  }
  else if (valor_letra == 20){
    pega_carac = "COMMA";
    return pega_carac;
  }
  else if (valor_letra == 21){
    pega_carac = "LPAREN";
    return pega_carac;
  }
  else if (valor_letra == 22){
    pega_carac = "RPAREN";
    return pega_carac;
  }
  else if (valor_letra == 23){
    pega_carac = "LBRACKET";
    return pega_carac;
  }
  else if (valor_letra == 24){
    pega_carac = "RBRACKET";
    return pega_carac;
  }
  else if (valor_letra == 25){
    pega_carac = "LBRACE";
    return pega_carac;
  }
  else if (valor_letra == 26){
    pega_carac = "RBRACE";
    return pega_carac;
  }
  else if (valor_letra == 27){
    pega_carac = "MAIN";
    return pega_carac;
  }
  else if (valor_letra == 28){
    pega_carac = "PRINTF";
    return pega_carac;
  }
  else {
    pega_carac = "ID";
    return pega_carac;
  }

}

/* /* aabc ******asva      */