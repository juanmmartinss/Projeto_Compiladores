#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

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
    valor = 0;
  }
  else if (isalpha(letra) != 0){
    valor = 1;
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
  else{
    valor = 18;
  }

  return valor;
}

void Tabela_DFA(Lex *lex, char letra, Buffer *buffer){

  int estado = 0;
  int valor;

//table driven
  while(lex->estado != 14 && lex->estado != 15){

    valor = pega_valor_para_matriz(letra);
    
    lex->estado = matriz_dfa[lex->estado][valor];
    //se for diferente de estado de aceitacao
    if(lex->estado != 14){
      break;
    }


  }
  if(lex->estado == 14){
    lex->estado = 1;
  }
}

void Verifica_palavra_reservada(char *palavra, Lex *lex){

  //ELSE, IF, INT, RETURN, VOID, WHILE, ID, NUM
  int valor;

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
  else if (strcmp(palavra, "id") == 0){
    lex->token = ID;
  }
  else if (strcmp(palavra, "num") == 0){
    lex->token = NUM;
  }

  return valor;

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