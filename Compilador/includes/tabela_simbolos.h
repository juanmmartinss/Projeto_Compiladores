//#ifndef TABELA_SIMBOLOS_H
//#define TABELA_SIMBOLOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "global.h"
//#include "funcs.h"

#define SIZE 211


typedef enum data{
    INTEIRO,
    VAZIO
} Tipo_dado;

//tipo de no
typedef enum tipo_no{
    DECLARACAO,
    EXPRESSAO,
    NADA
} Tipo_no;

//tipo de declaracao
typedef enum tipo_decl{
    IFK, 
    WHILEK, 
    INTK, 
    VOIDK, 
    NULOK, 
    VARIAVELK, 
    VETORK, 
    FUNCAOK, 
    PARAMETROVARIAVELK,
    PARAMETROVETORK,
    PARAMETROVOIDK 
} Tipo_declaracao;

//tipo de expressao
typedef enum tipo_expr{
    OPERANDO, // Operando.
    OPERADORRELACIONAL, // Operador relacional.
    CONSTANTE, // Valor numérico constante.
    IDK, // Uso de variável.
    CHAMADAFUNCAO, // Chamada de função.
    VETORPARAMETROK, // Uso de parâmetro vetor.
    ATRIBUICAOK, // Atribuição.
    NULO // Nulo.
} Tipo_expressao;


typedef struct hashNode {
    //SymbolTable symbol;
    int lineNumber;
    struct hashNode *next;
} HashNode;
typedef struct symbolTable {
    char nameID[20];//nome da variavel ou funcao
    char escopo[20];//escopo da variavel ou funcao
    Tipo_declaracao *typeID[20];//tipo da variavel ou funcao
    Tipo_dado *dataType[20]; // variavel ou funcao
    //Lex *lineNumber;
    HashNode *NumeroLinha;
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
//void insert(SymbolTable symbol);

//#endif