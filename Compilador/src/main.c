#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include <string.h>
#include <ctype.h>
#include "global.h"
//#include "parser.h"
//#include "parser.tab.h"

FILE *input_file = NULL;
Buffer *buffer = NULL;
Lex *lex = NULL;

char letra = '\0';
char c = '\0';
int linha_atual = 0;
int controle = 0;
char* pega_carac = NULL;

//raiz = NULL;

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


    lex->linha = 0;
    buffer->pos = 0;


    // for (int i = 0; i < buffer->size; i++) {
    //     get_lexema();
    // }
    parse();
    
    deallocate_buffer(buffer);
    libera_arvore(raiz);
    free(lex); // Libere a memória alocada para lex
    //free(pega_carac);

    fclose(input_file);

    


    //return 0;
}
