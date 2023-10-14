#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int matriz_dfa[13][21] = {
                         {2, 3, 14, 14, 14, 14, 14, 14, 14, 14, 14, 4, 10, 7, 8, 9, 14, 14, 14, 1, 15},
                         {2, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 14},
                         {14, 3, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 14},
                         {15, 14, 5, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 4, 14},
                         {5, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
                         {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5},
                         {15, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 13, 15, 15, 15, 15, 15, 15, 7, 14},
                         {15, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 15, 15, 15, 15, 15, 15, 8, 14},
                         {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 14, 15, 15, 15, 15, 15, 15, 9, 15},
                         {14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 11, 15, 15, 15, 15, 15, 15, 10, 14},
                         {14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 11, 14},
                         {15, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 14},
                         {15, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 13, 14},
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
  else if (letra == ' ' || letra == '\t'){
    valor = 19;
  }
  else{
    valor = 20;
  }

  return valor;
}

void Tabela_DFA(Lex *lex, char letra, Buffer *buffer){

  int estado;
  int valor;

  if (lex->estado != 14 && lex->estado != 15){

    if(lex->estado != 0){
      estado = lex->estado - 1;
    }
    else{
      estado = lex->estado;
    }

    valor = pega_valor_para_matriz(letra);

    lex->estado = matriz_dfa[estado][valor];

    printf("letra: %c\n", letra);

    printf("matriz na posicao [%d][%d]: %d\n", estado, valor, matriz_dfa[estado][valor]);

  }
  if(lex->estado == 14){//se o estado for 14, o lexema é um simbolo, estado de aceitação
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
  else if (valor_letra == 7){
    pega_carac = "NUM";
    return pega_carac;
  }

}