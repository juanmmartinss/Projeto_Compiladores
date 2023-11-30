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

symbolTable* initializeHashTable() {
    symbolTable *hashTable = (symbolTable*) malloc(sizeof(symbolTable) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
    return hashTable;
}

// void insert(SymbolTable symbol) {
//     unsigned int index = hash(symbol.nameID);
//     HashNode *newNode = (HashNode*) malloc(sizeof(HashNode));
//     newNode->symbol = symbol;
//     newNode->next = NULL;
//     if (hashTable[index] == NULL) {
//         hashTable[index] = newNode;
//     } else {
//         HashNode *temp = hashTable[index];
//         while (temp->next) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// symbolTable* search(char *nameID) {
//     unsigned int index = hash(nameID);
//     hashNode *temp = hashTable[index];
//     while (temp) {
//         if (strcmp(temp->symbol.nameID, nameID) == 0) {
//             return &temp->symbol;
//         }
//         temp = temp->next;
//     }
//     return NULL;
// }

// void display() {
//     for (int i = 0; i < SIZE; i++) {
//         hashNode *temp = hashTable[i];
//         while (temp) {
//             printf("Name ID: %s, Scope: %s, Type ID: %s, Data Type: %s, Line Number: %d\n",
//                    temp->symbol.nameID, temp->symbol.scope, temp->symbol.typeID,
//                    temp->symbol.dataType, temp->symbol.lineNumber);
//             temp = temp->next;
//         }
//     }
// }