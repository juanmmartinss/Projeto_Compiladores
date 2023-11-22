#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

pont_arv cria_arvore(char *palavra, int numero_linha){
    pont_arv raiz = (pont_arv) malloc(sizeof(Arvore));
    raiz->palavra = palavra;
    raiz->numero_linha = numero_linha;
    raiz->filho = NULL;
    raiz->irmao = NULL;
    return raiz;
}

pont_arv insere_irmao(pont_arv raiz, pont_arv no){
    if(raiz == NULL){
        return no;
    }
    pont_arv aux = raiz;
    while(aux->irmao != NULL){
        aux = aux->irmao;
    }
    aux->irmao = no;
    return raiz;
}

pont_arv insere_filho(pont_arv raiz, pont_arv no){
    if(raiz == NULL){
        return no;
    }
    raiz->filho = no;
    return raiz;
}

void imprime_arvore(pont_arv raiz, int nivel){
    if(raiz == NULL){
        return;
    }
    int i;
    for(i = 0; i < nivel; i++){
        printf("  ");
    }
    printf("%s\n", raiz->palavra);
    imprime_arvore(raiz->filho, nivel+1);
    imprime_arvore(raiz->irmao, nivel);
}

void libera_arvore(pont_arv raiz){
    if(raiz == NULL){
        return;
    }
    libera_arvore(raiz->filho);
    libera_arvore(raiz->irmao);
    free(raiz);
}
