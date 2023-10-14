#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int matriz_dfa[14][21] = {
                         {2, 3, 14, 14, 14, 14, 14, 14, 14, 14, 14, 4, 10, 7, 8, 9, 14, 14, 14, 1, 16},
                         {2, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15},
                         {15, 3, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 15},
                         {16, 15, 5, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 4, 15},
                         {5, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
                         {5, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 15, 5, 5, 5, 5, 5, 5, 5, 5, 5},
                         {15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 13, 16, 16, 16, 16, 16, 16, 7, 15},
                         {15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 12, 16, 16, 16, 16, 16, 16, 8, 15},
                         {16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 15, 16, 16, 16, 16, 16, 16, 9, 16},
                         {15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 11, 16, 16, 16, 16, 16, 16, 15, 15},
                         {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15},
                         {16, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 12, 15},
                         {16, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 13, 15},
                         {15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 14, 15},
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

void Tabela_DFA(Lex *lex, char letra, Buffer *buffer) {
    int estado;
    int valor;

    if (lex->estado != 15 && lex->estado != 16) {
        if (lex->estado != 0) {
            estado = lex->estado - 1;
        } else {
            estado = lex->estado;
        }

        printf("letra: |%c|\n", letra);
        //printf("matriz: |%d|\n", matriz_dfa[estado][valor]);

        valor = pega_valor_para_matriz(letra);

        lex->estado = matriz_dfa[estado][valor];
    }

    if (lex->estado == 15) { // se o estado for 15, o lexema é um símbolo, estado de aceitação
        buffer->data[buffer->pos - 1] = letra; // Armazena a última letra no buffer
        lex->Aux = 1;
    }
}


void Verifica_palavra_reservada(char *palavra, Lex *lex){

  //ELSE, IF, INT, RETURN, VOID, WHILE, ID, NUM
  //int valor;

  if (strcmp(palavra, "if") == 0){
    lex->token = IF;
  }
  else if (strcmp(palavra, "else") == 0){ 
    lex->token = ELSE;
  }
  else if (strcmp(palavra, "int") == 0){
    lex->token = INT;
  }
  else if (strcmp(palavra, "return") == 0){
    lex->token = RETURN;
  }
  else if (strcmp(palavra, "void") == 0){
    lex->token = VOID;
  }
  else if (strcmp(palavra, "while") == 0){
    lex->token = WHILE;
  }
  else if (strcmp(palavra, "num") == 0){
    lex->token = NUM;
  }
  // else if (strcmp(palavra, "-") == 0){
  //   lex->token = MINUS;
  // }
  // else if (strcmp(palavra, "+") == 0){
  //   lex->token = PLUS;
  // }
  // else if (strcmp(palavra, "*") == 0){
  //   lex->token = TIMES;
  // }
  // else if (strcmp(palavra, "/") == 0){
  //   lex->token = OVER;
  // }
  // else if (strcmp(palavra, "<") == 0){
  //   lex->token = LT;
  // }
  // else if (strcmp(palavra, "<=") == 0){
  //   lex->token = LE;
  // }
  // else if (strcmp(palavra, ">") == 0){
  //   lex->token = GT;
  // }
  // else if (strcmp(palavra, ">=") == 0){
  //   lex->token = GE;
  // }
  // else if (strcmp(palavra, "==") == 0){
  //   lex->token = EQ;
  // }
  // else if (strcmp(palavra, "!=") == 0){
  //   lex->token = NE;
  // }
  // else if (strcmp(palavra, "=") == 0){
  //   lex->token = ASSIGN;
  // }
  // else if (strcmp(palavra, ";") == 0){
  //   lex->token = SEMI;
  // }
  // else if (strcmp(palavra, ",") == 0){
  //   lex->token = COMMA;
  // }
  // else if (strcmp(palavra, "(") == 0){
  //   lex->token = LPAREN;
  // }
  // else if (strcmp(palavra, ")") == 0){
  //   lex->token = RPAREN;
  // }
  // else if (strcmp(palavra, "[") == 0){
  //   lex->token = LBRACKET;
  // }
  // else if (strcmp(palavra, "]") == 0){
  //   lex->token = RBRACKET;
  // }
  // else if (strcmp(palavra, "{") == 0){
  //   lex->token = LBRACE;
  // }
  // else if (strcmp(palavra, "}") == 0){
  //   lex->token = RBRACE;
  // }
  // else if (strcmp(palavra, "main") == 0){
  //   lex->token = MAIN;
  // }
  // else if (strcmp(palavra, "printf") == 0){
  //   lex->token = PRINTF;
  // }
  else{
    lex->token = ID;
  }

  //return valor;

}
 
char* Pega_ID(int valor_letra, Lex *lex){
    //ELSE, IF, INT, RETURN, VOID, WHILE, ID, NUM
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
  else if (valor_letra == 6){
    pega_carac = "ID";
    return pega_carac;
  }
  // else if (valor_letra == 7){
  //   pega_carac = "NUM";
  //   return pega_carac;
  // }
  // else if (valor_letra == 8){
  //   pega_carac = "+";
  //   return pega_carac;
  // }
  // else if (valor_letra == 9){
  //   pega_carac = "-";
  //   return pega_carac;
  // }
  // else if (valor_letra == 10){
  //   pega_carac = "*";
  //   return pega_carac;
  // }
  // else if (valor_letra == 11){
  //   pega_carac = "/";
  //   return pega_carac;
  // }
  // else if (valor_letra == 12){
  //   pega_carac = "<";
  //   return pega_carac;
  // }
  // else if (valor_letra == 13){
  //   pega_carac = "<=";
  //   return pega_carac;
  // }
  // else if (valor_letra == 14){
  //   pega_carac = ">";
  //   return pega_carac;
  // }
  // else if (valor_letra == 16){
  //   pega_carac = ">=";
  //   return pega_carac;
  // }
  // else if (valor_letra == 16){
  //   pega_carac = "==";
  //   return pega_carac;
  // }
  // else if (valor_letra == 17){
  //   pega_carac = "!=";
  //   return pega_carac;
  // }
  // else if (valor_letra == 18){
  //   pega_carac = "=";
  //   return pega_carac;
  // }
  // else if (valor_letra == 19){
  //   pega_carac = ";";
  //   return pega_carac;
  // }
  // else if (valor_letra == 20){
  //   pega_carac = ",";
  //   return pega_carac;
  // }
  // else if (valor_letra == 21){
  //   pega_carac = "(";
  //   return pega_carac;
  // }
  // else if (valor_letra == 22){
  //   pega_carac = ")";
  //   return pega_carac;
  // }
  // else if (valor_letra == 23){
  //   pega_carac = "[";
  //   return pega_carac;
  // }
  // else if (valor_letra == 24){
  //   pega_carac = "]";
  //   return pega_carac;
  // }
  // else if (valor_letra == 25){
  //   pega_carac = "{";
  //   return pega_carac;
  // }
  // else if (valor_letra == 26){
  //   pega_carac = "}";
  //   return pega_carac;
  // }
  // else if (valor_letra == 27){
  //   pega_carac = "main";
  //   return pega_carac;
  // }
  // else if (valor_letra == 28){
  //   pega_carac = "printf";
  //   return pega_carac;
  // }
  // else{
  //   pega_carac = "ERROR";
  //   return pega_carac;
  // }

}