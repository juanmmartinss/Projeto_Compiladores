#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_simbolos.h"

#define SIZE 211

unsigned int hash(char *key) {//funcao para gerar o hash
    unsigned int value = 0;
    for (int i = 0; i < strlen(key); i++) {
        value = value * 37 + key[i];
    }
    return value % SIZE;
}

tabelaSimbolos* initializeHashTable() {//inicializa a tabela
    tabelaSimbolos *hashTable = (tabelaSimbolos*) malloc(sizeof(tabelaSimbolos) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
    return hashTable;
}

//funcao para inserir na tabela
void inserttable(tabelaSimbolos *hashtable, Tipo_declaracao *typeID, Tipo_dado *dataType, char *nameID, char *escopo, int linha) {
    int index = hash(nameID);
    tabelaSimbolos list = hashtable[index];

    if(list == NULL){
        list = (tabelaSimbolos) malloc(sizeof(SymbolTable));
        //strcpy(list->dataType, dataType);
        strcpy(list->nameID, nameID);
        strcpy(list->escopo, escopo);
        list->dataType = dataType;
        list->typeID = typeID;
        list->NumeroLinha[list->linhasvetor] = linha;
        list->linhasvetor++;
        list->next = NULL;
        hashtable[index] = list;
    }else{
        while(list->next != NULL){
            list = list->next;
        }
        list->next = (tabelaSimbolos) malloc(sizeof(SymbolTable));
        strcpy(list->next->nameID, nameID);
        strcpy(list->next->escopo, escopo);
        list->next->dataType = dataType;
        list->next->typeID = typeID;
        list->next->NumeroLinha[list->linhasvetor] = linha;
        list->linhasvetor++;
        list->next->next = NULL;
    }
}

void inserelinha(tabelaSimbolos *hashtable, char *nameID, int linha, char *escopo) {
    int index = hash(nameID);
    tabelaSimbolos list = hashtable[index];

    while(list != NULL){
        if(strcmp(list->nameID, nameID) == 0 && strcmp(list->escopo, escopo) == 0){
            list->NumeroLinha[list->linhasvetor] = linha;
            list->linhasvetor++;
            break;
        }
        list = list->next;
    }
    

}

//funcao para imprimir a tabela
void printatabela(tabelaSimbolos *hashtable) {

    printf("%-10s | %-10s | %-15s | %-15s | %s\n", "Nome", "Escopo", "Tipo", "Tipo de Dado", "Linhas");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < SIZE; i++) {
        if (hashtable[i] != NULL) {
            tabelaSimbolos list = hashtable[i];
            while (list != NULL) {
                printf("%-10s | %-10s | %-15d | %-15d | ", list->nameID, list->escopo, (int)list->typeID, (int)list->dataType);

                for(int j = 0; j < list->linhasvetor; j++){
                    if(list->NumeroLinha[j] == list->NumeroLinha[j+1]){
                        while(list->NumeroLinha[j] == list->NumeroLinha[j+1]){
                            j++;
                        }
                    }
                    printf("%d ", list->NumeroLinha[j]);
                }

                printf("\n");
                list = list->next;
            }
        }
    }
}

void tranformaTipoIntVoid(int tipo, char *palavra){

    if(tipo == 0){
        strcpy(palavra, "INT");
    }
    else if(tipo == 1){
        strcpy(palavra, "VOID");
    }

}

void transformaTipo(int tipo, char *palavra){

    if(tipo == 0){
        strcpy(palavra, "IFK");
    }
    else if(tipo == 1){
        strcpy(palavra, "WHILEK");
        //palavra = "WHILEK";
    }
    else if(tipo == 2){
        strcpy(palavra, "INTK");
        //palavra = "INTK";
    }
    else if(tipo == 3){
        strcpy(palavra, "VOIDK");
    }
    else if(tipo == 4){
        strcpy(palavra, "NULOK");
    }
    else if(tipo == 5){
        strcpy(palavra, "VARIAVELK");
    }
    else if(tipo == 6){
        strcpy(palavra, "VETORK");
    }
    else if(tipo == 7){
        strcpy(palavra, "FUNCAOK");
    }
    else if(tipo == 8){
        strcpy(palavra, "PARAMETROVARIAVELK");
    }
    else if(tipo == 9){
        strcpy(palavra, "PARAMETROVETORK");
    }
    else if(tipo == 10){
        strcpy(palavra, "PARAMETROVOIDK");
    }

}


