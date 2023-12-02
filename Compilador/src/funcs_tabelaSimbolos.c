#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_simbolos.h"
//#include "global.h"

#define SIZE 211

unsigned int hash(char *key) {//funcao para gerar o hash
    unsigned int value = 0;
    for (int i = 0; i < strlen(key); i++) {
        value = value * 37 + key[i];
    }
    return value % SIZE;
}

tabelaSimbolos* initializeHashTable() {
    tabelaSimbolos *hashTable = (tabelaSimbolos*) malloc(sizeof(tabelaSimbolos) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
    return hashTable;
}

void inserttable(tabelaSimbolos *hashtable, Tipo_declaracao *typeID, Tipo_dado *dataType, char *nameID, char *escopo, int linha) {
    int index = hash(nameID);
    tabelaSimbolos list = hashtable[index];

    if(list == NULL){
        list = (tabelaSimbolos) malloc(sizeof(SymbolTable));
        strcpy(list->nameID, nameID);
        strcpy(list->escopo, escopo);
        list->NumeroLinha = linha;
        list->next = NULL;
        hashtable[index] = list;
    }else{
        while(list->next != NULL){
            list = list->next;
        }
        list->next = (tabelaSimbolos) malloc(sizeof(SymbolTable));
        strcpy(list->next->nameID, nameID);
        strcpy(list->next->escopo, escopo);
        list->next->NumeroLinha = linha;
        list->next->next = NULL;
    }
}

void printatabela(tabelaSimbolos *hashtable) {
    for (int i = 0; i < SIZE; i++) {
        if (hashtable[i] != NULL) {
            tabelaSimbolos list = hashtable[i];
            while (list != NULL) {
                printf("Nome: %s | Escopo: %s | Linha: %d\n", list->nameID, list->escopo, list->NumeroLinha);
                list = list->next;
            }
        }
        else{
            printf("NULL\n");
        }
    }
}


