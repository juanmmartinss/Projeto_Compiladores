#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "parser_arvore.h"
//#include "global.h"


pont_arv cria_no(pont_arv no){

    printf("cria no\n");
    no = (pont_arv)malloc(sizeof(Arvore));
    no->filho1 = NULL;
    no->filho2 = NULL;
    no->filho3 = NULL;
    no->irmao = NULL;
    no->tipo = NULL;
    no->valor = NULL;
    memset(no->lexema, 0, 20);
    return no;
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
    if(raiz->filho1 == NULL){
        raiz->filho1 = no;
    }else if(raiz->filho2 == NULL){
        raiz->filho2 = no;
    }else if(raiz->filho3 == NULL){
        raiz->filho3 = no;
    }else{
        printf("Erro: no %s com mais de 3 filhos\n", raiz->lexema);
    }
    return raiz;
}

void imprime_arvore(pont_arv raiz, int nivel){
    
    if(raiz == NULL){
        return;
    }

    int i;

    for(i = 0; i < nivel; i++){
        printf("      ");
    }
    printf("%s\n", raiz->lexema);
    imprime_arvore(raiz->filho1, nivel+1);
    imprime_arvore(raiz->filho2, nivel+1);
    imprime_arvore(raiz->filho3, nivel+1);
    imprime_arvore(raiz->irmao, nivel);

}

void libera_arvore_sintatica(pont_arv raiz){
    if(raiz == NULL){
        return;
    }
    libera_arvore_sintatica(raiz->filho1);
    libera_arvore_sintatica(raiz->filho2);
    libera_arvore_sintatica(raiz->filho3);
    libera_arvore_sintatica(raiz->irmao);
    free(raiz);
}
