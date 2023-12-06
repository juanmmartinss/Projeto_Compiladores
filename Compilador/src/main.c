/*
Aluno: Juan Marcos Martins
RA:156.470
Compiladores - 2023-1
Universidade Federal de São Paulo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcs.h"
#include "parser_arvore.h"
#include "tabela_simbolos.h"
#include "semantico.h"

FILE *input_file = NULL;
Buffer *buffer = NULL;
Lex *lex = NULL;
Pilha *pilha = NULL;
//static No *raiz = NULL; // Árvore binária de busca balanceada

char letra = '\0';
char c = '\0';
int linha_atual = 0;
int controle = 0;
char* pega_carac = NULL;

pont_arv parse(void);

int main(int argc, char *argv[]) {

    if (argc != 2) {//verifica se o arquivo foi passado
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");//abre o arquivo

    if (input_file == NULL) {//verifica se o arquivo foi aberto
        fprintf(stderr, "Failed to open input file\n");
        exit(1);
    }

    int BUFFER_SIZE = 256;

    buffer = allocate_buffer(BUFFER_SIZE);//aloca o buffer
    buffer->data = (char*) malloc(BUFFER_SIZE * sizeof(char));

    buffer->size = BUFFER_SIZE;
    buffer->pos = 0;

    if (buffer == NULL) {//verifica se o buffer foi alocado
        fprintf(stderr, "Failed to allocate buffer\n");
        fclose(input_file);
        exit(1);
    }

    lex = (Lex *)malloc(sizeof(Lex)); // Aloque memória para lex

    lex->linha = 0;
    lex->estado = 0; 
    lex->aux = 0; 

    if (lex == NULL) {
        fprintf(stderr, "Failed to allocate memory for lex\n");
        fclose(input_file);
        exit(1);
    }


    pega_carac = (char*)malloc(sizeof(char)*128);

    if (pega_carac == NULL) {
        fprintf(stderr, "Failed to allocate memory for pega_carac\n");
        fclose(input_file);
        exit(1);
    }

    pilha = (Pilha *)malloc(sizeof(Pilha)); // Aloque memória para lex
    
    initialize(pilha);

    lex->linha = 0;
    buffer->pos = 0;

    pont_arv arvore = parse();

    if (arvore == NULL) {
        printf("Erro ao gerar arvore!\n");
        //acaba o programa
        fclose(input_file);
        exit(1);
    }

    tabelaSimbolos *tabela = initializeHashTable();

    inserttable(tabela, (void*)7, (void*)0, "input", "global", 0);
    inserttable(tabela, (void*)7, (void*)1, "output", "global", 0);

    analise_semantica(arvore, tabela, "global");

    while (1) {
        printf("Deseja imprimir a arvore ou a tabela? (a/t/n)\n");
        char opcao;
        scanf("%c", &opcao);
        getchar();
        if (opcao == 'a') {
            system("clear"); 
            printf("-----------------ARVORE SINTATICA-----------------\n");
            imprime_arvore(arvore, 0);
            printf("---------------------------------------------------\n");
            printf("\n");
        }
        else if (opcao == 't') {
            system("clear");
            printf("-------------------------------TABELA DE SIMBOLOS------------------------------\n");
            printatabela(tabela);
            printf("--------------------------------------------------------------------------------\n");
            printf("\n");
        }
        else if (opcao == 'n') {
            break;
        }
    }

    chama_desaloca_arvore();
    
    deallocate_buffer(buffer);
    
    free(lex); // Libere a memória alocada para lex
    //free(pega_carac);
    liberar_pilha(pilha);

    libera_arvore_sintatica(arvore);

    fclose(input_file);

    return 0;
}
