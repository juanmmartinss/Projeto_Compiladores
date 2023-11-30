#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "funcs.h"

#define SIZE 20

typedef struct symbolTable {
    char nameID[20];//nome da variavel ou funcao
    char scope[20];//escopo da variavel ou funcao
    Tipo_declaracao *typeID[20];//tipo da variavel ou funcao
    Tipo_dado *dataType[20]; // variavel ou funcao
    Lex *lineNumber;
} SymbolTable;

typedef struct hashNode {
    SymbolTable symbol;
    struct hashNode *next;
} HashNode;

HashNode* hashTable[SIZE];


SymbolTable *tabelasimbolos;

void initializeHashTable();

#endif