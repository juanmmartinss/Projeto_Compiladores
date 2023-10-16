#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int matriz_dfa[15][21] = {
                         {2, 3, 15, 15, 15, 15, 15, 15, 15, 15, 15, 4, 11, 8, 9, 10, 15, 15, 15, 1, 17},
                         {2, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17},
                         {16, 3, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17},
                         {16, 16, 5, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 4, 17},
                         {5, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
                         {5, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5},
                         {16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17},
                         {16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 14, 17, 17, 17, 17, 17, 17, 7, 17},
                         {16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 13, 17, 17, 17, 17, 17, 17, 9, 17},
                         {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 16, 17, 17, 17, 17, 17, 17, 9, 17},
                         {16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 12, 17, 17, 17, 17, 17, 17, 16, 17},
                         {16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17},
                         {17, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 12, 17},
                         {17, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 13, 17},
                         {16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16},
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
    int isSpecialChar = 0; // Flag to track if the character is a special character
    int linha;
    //lex->aux = 0;

    if (lex->estado != 16 && lex->estado != 17) {
        if (lex->estado != 0) {//para se adequar a matriz, pois a martiz começa em 0 mas a logica esta para começar em 1
            estado = lex->estado - 1;
        } else {
            estado = lex->estado;
        }

        valor = pega_valor_para_matriz(letra);

        lex->estado = matriz_dfa[estado][valor];
    }
    

    if (lex->estado == 16) { // If the state is 16, the lexeme is a symbol (acceptance state)
        isSpecialChar = 1;
    }

    if (lex->estado == 17 && linha != lex->linha) {
        lex->aux = 1;
        linha = lex->linha;
        return 1;
    }

    if (!isSpecialChar) {
        buffer->data[buffer->pos - 1] = letra; // Store the last letter in the buffer if it's not a special character
    } else {
        buffer->pos--; // Move back one position in the buffer to include the special character in the next lexeme
    }

    return isSpecialChar;
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
  else if (strcmp(palavra, "-") == 0){
    lex->token = MINUS;
  }
  else if (strcmp(palavra, "+") == 0){
    lex->token = PLUS;
  }
  else if (strcmp(palavra, "*") == 0){
    lex->token = TIMES;
  }
  else if (strcmp(palavra, "/") == 0){
    lex->token = OVER;
  }
  else if (strcmp(palavra, "<") == 0){
    lex->token = LT;
  }
  else if (strcmp(palavra, "<=") == 0){
    lex->token = LE;
  }
  else if (strcmp(palavra, ">") == 0){
    lex->token = GT;
  }
  else if (strcmp(palavra, ">=") == 0){
    lex->token = GE;
  }
  else if (strcmp(palavra, "==") == 0){
    lex->token = EQ;
  }
  else if (strcmp(palavra, "!=") == 0){
    lex->token = NE;
  }
  else if (strcmp(palavra, "=") == 0){
    lex->token = ASSIGN;
  }
  else if (strcmp(palavra, ";") == 0){
    lex->token = SEMI;
  }
  else if (strcmp(palavra, ",") == 0){
    lex->token = COMMA;
  }
  else if (strcmp(palavra, "(") == 0){
    lex->token = LPAREN;
  }
  else if (strcmp(palavra, ")") == 0){
    lex->token = RPAREN;
  }
  else if (strcmp(palavra, "[") == 0){
    lex->token = LBRACKET;
  }
  else if (strcmp(palavra, "]") == 0){
    lex->token = RBRACKET;
  }
  else if (strcmp(palavra, "{") == 0){
    lex->token = LBRACE;
  }
  else if (strcmp(palavra, "}") == 0){
    lex->token = RBRACE;
  }
  else if (strcmp(palavra, "main") == 0){
    lex->token = MAIN;
  }
  else if (strcmp(palavra, "printf") == 0){
    lex->token = PRINTF;
  }
  else{
    lex->token = ID;
  }

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