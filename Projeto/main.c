#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {//verifica se o arquivo foi passado
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");//abre o arquivo

    if (input_file == NULL) {//verifica se o arquivo foi aberto
        fprintf(stderr, "Failed to open input file\n");
        exit(1);
    }

    int BUFFER_SIZE = 256;

    Buffer *buffer = allocate_buffer(BUFFER_SIZE);//aloca o buffer
    buffer->size = BUFFER_SIZE;

    if (buffer == NULL) {//verifica se o buffer foi alocado
        fprintf(stderr, "Failed to allocate buffer\n");
        fclose(input_file);
        exit(1);
    }

    Lex *lex = (Lex *)malloc(sizeof(Lex)); // Aloque memória para lex

    if (lex == NULL) {
        fprintf(stderr, "Failed to allocate memory for lex\n");
        fclose(input_file);
        exit(1);
    }


    char* pega_carac = (char*)malloc(sizeof(char)*64);
    char letra;
    char c;

    lex->linha = 0;
    buffer->pos = 0;
    lex->Aux = 0;
    //int flag = 0;


    while ((letra = get_next_char(buffer, input_file, lex)) != '\0') {//pega a linha do arquivo e coloca no buffer

        buffer->pos = 0;
        
       //pega a linha do arquivo, e coloca no contador para armazenar em qual linha esta o lexema

        for (int i = 0; i < buffer->size; i++) {//percorre a linha do arquivo

            //lex->estado = INICIO;

            for (int k = 0; k < 64; k++) { // Zera o vetor lexema
                    lex->lexema[k] = '\0';
            }

            for (int j = 0; j < 64; j++) {//percorre o lexema da linha

                c = get_next_char(buffer, input_file, lex);


                Tabela_DFA(lex, c, buffer);//verifica se o char é um simbolo

                if(lex->Aux == 0){

                    lex->lexema[j] = c;
                }
                else{
                    break;
                }
            }

            //tira espacos em branco do inicio do lexema
            char *aux;

            //monta novo vetor sem espacos no comeco
            for (int i = 0; i < strlen(lex->lexema); i++) {
                if (isspace(lex->lexema[i]) == 0) {
                    aux = &lex->lexema[i];
                    break;
                }
            }


            Verifica_palavra_reservada(aux, lex);//verifica se o lexema é uma palavra reservada

            if (aux[0] != '\0') { // Verifica se a string não está vazia.

                pega_carac = Pega_ID(lex->token, lex);//pega o token e o lexema e retorna o token em string 

                printf("Token: %s, Linha: %d, Lexema: %s \n",pega_carac, lex->linha, aux);
            }

            lex->estado = INICIO;
            lex->Aux = 0;

        }
    }

    deallocate_buffer(buffer);
    free(lex); // Libere a memória alocada para lex
    fclose(input_file);

    return 0;
}
