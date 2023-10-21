#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

PalavraReservada tabela_hash[HASH_SIZE] = {
  {"if", IF},
  {"else", ELSE},
  {"int", INT},
  {"return", RETURN},
  {"void", VOID},
  {"while", WHILE},
  {"num", NUM},
  {"+", PLUS},
  {"-", MINUS},
  {"*", TIMES},
  {"/", OVER},
  {"<", LT},
  {"<=", LE},
  {">", GT},
  {">=", GE},
  {"==", EQ},
  {"!=", NE},
  {"=", ASSIGN},
  {";", SEMI},
  {",", COMMA},
  {"(", LPAREN},
  {")", RPAREN},
  {"[", LBRACKET},
  {"]", RBRACKET},
  {"{", LBRACE},
  {"}", RBRACE},
  {"main", MAIN},
  {"printf", PRINTF}
};

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

void Verifica_palavra_reservada(char *palavra, Lex *lex) {
    int hash = 0;
    int counter = 0; // contador para verificar se o loop esta em loop infinito

    for (int i = 0; palavra[i] != '\0'; i++) {//pega o tamanho da palavra
        //printf("palavra[%d] = %c\n", i, palavra[i]);
        hash = (hash * 31 + palavra[i]) % HASH_SIZE;//faz o hash da palavra, para saber em qual posição da tabela hash ela esta
    }
    while (strcmp(tabela_hash[hash].palavra, "") != 0) {//verifica se a palavra é igual a palavra da tabela hash
        if (strcmp(palavra, tabela_hash[hash].palavra) == 0) {//se for igual, armazena o token
            lex->token = tabela_hash[hash].token;
            return;//retorna para a main, para nao continuar o loop
        }
        hash = (hash + 1) % HASH_SIZE;//se não for igual, incrementa o hash para verificar a proxima palavra
        counter++; // incrementa o contador
        if (counter > HASH_SIZE) { // se o contador for maior que o tamanho da tabela hash, sai do loop
            break;
        }
    }
    lex->token = ID;
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