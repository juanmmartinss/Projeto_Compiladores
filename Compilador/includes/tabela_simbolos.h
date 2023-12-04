#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "global.h"
//#include "funcs.h"
#include "parser_arvore.h"

#define SIZE 211

typedef struct hashNode {
    //SymbolTable symbol;
    int lineNumber;
    struct hashNode *next;
} HashNode;

typedef struct symbolTable {
    char nameID[20];//nome da variavel ou funcao
    char escopo[20];//escopo da variavel ou funcao
    Tipo_declaracao *typeID;//tipo da variavel ou funcao
    Tipo_dado *dataType; // variavel ou funcao
    int linhasvetor;
    //Lex *lineNumber;
    HashNode *NumeroLinha[20];
    struct symbolTable *next;
} SymbolTable;

typedef struct hashTable{
    SymbolTable *table[SIZE];
} HashTable;


typedef HashNode* hashTable;

typedef SymbolTable* tabelaSimbolos;

unsigned int hash(char *key);
tabelaSimbolos* initializeHashTable();
void inserttable(tabelaSimbolos *hashtable, Tipo_declaracao *typeID, Tipo_dado *dataType, char *nameID, char *escopo, int linha);
void printatabela(tabelaSimbolos *hashtable);
void transformaTipo(int tipo, char *palavra);
void inserelinha(tabelaSimbolos *hashtable, char *nameID, int linha, char *escopo);
void tranformaTipoIntVoid(int tipo, char *palavra);

//void insert(SymbolTable symbol);

#endif