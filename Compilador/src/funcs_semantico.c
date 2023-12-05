#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_simbolos.h"
#include "semantico.h"
#include "parser_arvore.h"
#include <ctype.h>

int tipofuncao;


int buscarnatabela(pont_arv arv, tabelaSimbolos *hashtable, char *escopo, char *lexema){//retorna 1 se nao encontrar o identificador na tabela
    int index = hash(lexema);
    tabelaSimbolos list = hashtable[index];

    if(list == NULL){
        return 1;
    }
    else{
        while(list != NULL){
            if(strcmp(list->nameID, lexema) == 0 ){
                if((strcmp(list->escopo, escopo) == 0)||(strcmp(list->escopo, "global") == 0)){//compara escopo
                    return 0;
                }
            }
            list = list->next;
        }
    }
    return 1;
}

int buscarnatabelatipo(pont_arv arv, tabelaSimbolos *hashtable, char *escopo, char *lexema){//retorna 1 se nao encontrar o identificador na tabela
    int index = hash(lexema);
    tabelaSimbolos list = hashtable[index];

    if(list == NULL){
        return -1;
    }
    else{
        while(list != NULL){
            if(strcmp(list->nameID, lexema) == 0 ){
                if((strcmp(list->escopo, escopo) == 0)||(strcmp(list->escopo, "global") == 0)){
                    return list->dataType;
                }
            }
            list = list->next;
        }
    }
    return -1;
}

void analise_semantica(pont_arv arv, tabelaSimbolos *hashtable, char *escopo){
    int controle; int monit; int flag;int controletabela;
    
    if(arv == NULL){
        return;
    }

    if(arv->tipo == EXPRESSAO){

        if(arv->tipoexpressao == OPERANDO){
            analise_semantica(arv->filho1, hashtable, escopo);
            analise_semantica(arv->filho2, hashtable, escopo);
        }
        else if(arv->tipoexpressao == OPERADORRELACIONAL)
        {
            analise_semantica(arv->filho1, hashtable, escopo);
            analise_semantica(arv->filho2, hashtable, escopo);
        }
        else if(arv->tipoexpressao == CONSTANTE)
        {
            
        } 
        else if (arv->tipoexpressao == IDK){
            controle = buscarnatabela(arv, hashtable, escopo, arv->lexema);
            if(controle == 1){//se nao encontrar o identificador na tabela
                controletabela = buscarnatabelatipo(arv, hashtable, escopo, arv->lexema);
                if(controletabela == VAZIO){
                    monit = 4;
                    errosemantico(arv->lexema, arv->linha, monit);
                }
                else{
                    monit = 4;
                    errosemantico(arv->lexema, arv->linha, monit);
                }
            }
            else{
                inserelinha(hashtable, arv->lexema, arv->linha, escopo);
                inserelinha(hashtable, arv->lexema, arv->linha, "global");
                //compara escopo
            }

        } 
        else if (arv->tipoexpressao == CHAMADAFUNCAO){

            if(controle = buscarnatabela(arv, hashtable, escopo, arv->lexema) == 1){//se nao encontrar o identificador na tabela
                    monit = 5;
                    errosemantico(arv->lexema, arv->linha, monit);
            }
            else{
                inserelinha(hashtable, arv->lexema, arv->linha, "global");
            }
        } 
        else if (arv->tipoexpressao == VETORPARAMETROK){
                controletabela = buscarnatabelatipo(arv, hashtable, escopo, arv->filho1->lexema);

                if(controletabela != -1){//se nao encontrar o identificador na tabela
                    if(controletabela == VAZIO){
                        monit = 4;
                        errosemantico(arv->filho1->lexema, arv->linha, monit);
                    }
                    else{
                        inserelinha(hashtable, arv->lexema, arv->linha, escopo);
                        inserelinha(hashtable, arv->lexema, arv->linha, "global");
                    }
                }
                else{
                    inserttable(hashtable, arv->tipodeclaracao, arv->tipo, arv->filho1->lexema, escopo, arv->linha);
                    controle = 0;
                }
        } 
        else if (arv->tipoexpressao == ATRIBUICAOK){
            if(strcmp(arv->filho2->lexema, "input") != 0){
                if(strcmp(arv->filho2->lexema, "output") != 0){
                    if(arv->filho2->tipoexpressao == CHAMADAFUNCAO){
                        controletabela = buscarnatabelatipo(arv, hashtable, escopo, arv->filho2->lexema);
                        if(controletabela != -1){
                            if(controletabela == VAZIO){

                                monit = 3;
                                errosemantico(arv->filho2->lexema, arv->linha, monit);
                            }
                            else{
                                inserelinha(hashtable, arv->filho2->lexema, arv->linha, "global");
                            }
                        }
                        else{
                            monit = 3;
                            errosemantico(arv->filho2->lexema, arv->linha, monit);

                        }

                    }
                }
                else{
                    inserelinha(hashtable, arv->filho2->lexema, arv->linha, "global");
                }
            }
            else{
                inserelinha(hashtable, arv->filho2->lexema, arv->linha, "global");
            }

        } 
    } else if (arv->tipo == DECLARACAO){
        if(arv->tipodeclaracao == IFK){
            if(arv->linha != 0 ){
                controle = buscarnatabela(arv, hashtable, escopo, arv->lexema);
                if(controle == 1){//se nao encontrar o identificador na tabela
                    
                    if(verificaPalavraReservada(arv->lexema) != 0){
                        inserttable(hashtable, arv->tipodeclaracao, tipofuncao, arv->lexema, "global", arv->linha);
                        controle = 0;
                    }
                }
                else{
                    monit = 1;
                    errosemantico(arv->lexema, arv->linha, monit);
                }
            }

        }
        else if(arv->tipodeclaracao == WHILEK){
            if(arv->linha != 0 ){
                controle = buscarnatabela(arv, hashtable, escopo, arv->lexema);
                if(controle == 1){//se nao encontrar o identificador na tabela
                    
                    if(verificaPalavraReservada(arv->lexema) != 0){
                        inserttable(hashtable, arv->tipodeclaracao, tipofuncao, arv->lexema, "global", arv->linha);
                        controle = 0;
                    }
                }
                else{
                    monit = 1;
                    errosemantico(arv->lexema, arv->linha, monit);
                }
            }
        }
        else if(arv->tipodeclaracao == INTK){
            controle = buscarnatabela(arv, hashtable, escopo, arv->filho1->lexema);
            if(controle == 1){//se nao encontrar o identificador na tabela
                    inserttable(hashtable, arv->tipodeclaracao, arv->tipo, arv->filho1->lexema, escopo, arv->linha);
                    controle = 0;
            }
            else{
                inserelinha(hashtable, arv->filho1->lexema, arv->linha, "global");

            }
        }
        else if(arv->tipodeclaracao == VOIDK){
        }
        else if(arv->tipodeclaracao == NULOK){
        }
        else if(arv->tipodeclaracao == VARIAVELK){
            if(strcmp(arv->lexema, "VOID") == 0){
                monit = 2;
                errosemantico(arv->filho1->lexema, arv->linha, monit);
            }

            if(controle = buscarnatabela(arv, hashtable, escopo, arv->filho1->lexema) == 1){//se nao encontrar o identificador na tabela
                    inserttable(hashtable, arv->tipodeclaracao, arv->tipo, arv->filho1->lexema, escopo, arv->linha);
                    controle = 0;
            }
            else{
                monit = 1;
                errosemantico(arv->filho1->lexema, arv->linha, monit);
            }
                

        }else if(arv->tipodeclaracao == VETORK)
        {
            controle = buscarnatabela(arv, hashtable, escopo, arv->filho1->lexema);
            if(controle == 1){//se nao encontrar o identificador na tabela
                inserttable(hashtable, arv->tipodeclaracao, arv->tipo, arv->filho1->lexema, escopo, arv->linha);
                controle = 0;
            }
            else{
                inserelinha(hashtable, arv->filho1->lexema, arv->linha, escopo);
            }

        }else if(arv->tipodeclaracao == FUNCAOK)
        {
            escopo = arv->filho2->lexema;
            if(strcmp(arv->lexema, "VOID") == 0){
                tipofuncao = 1;
            }else{
                tipofuncao = 0;
            }

        }else if(arv->tipodeclaracao == PARAMETROVARIAVELK)
        {
            if(controle = buscarnatabela(arv, hashtable, escopo, arv->filho1->lexema) == 1){//se nao encontrar o identificador na tabela
                    inserttable(hashtable, arv->tipodeclaracao, arv->tipo, arv->filho1->lexema, escopo, arv->linha);
                    controle = 0;
            }
            else{
                monit = 1;
                errosemantico(arv->filho1->lexema, arv->linha, monit);
            }

        }
        else if(arv->tipodeclaracao == PARAMETROVETORK){
                controletabela = buscarnatabelatipo(arv, hashtable, escopo, arv->filho1->lexema);

                if(controletabela != -1){
                    if(controletabela == VAZIO){
                        monit = 4;
                        errosemantico(arv->filho1->lexema, arv->linha, monit);
                    }
                    else{
                        monit = 4;
                        errosemantico(arv->filho1->lexema, arv->linha, monit);
                    }
                }
                else{
                    inserttable(hashtable, arv->tipodeclaracao, arv->tipo, arv->filho1->lexema, escopo, arv->linha);
                    controle = 0;
                }

            
        }
        else if(arv->tipodeclaracao == PARAMETROVOIDK){

        }
    }

    if(arv->filho1 != NULL){
        analise_semantica(arv->filho1, hashtable, escopo);
    }
    if(arv->filho2 != NULL){
        analise_semantica(arv->filho2, hashtable, escopo);

    }
    if(arv->filho3 != NULL){
        analise_semantica(arv->filho3, hashtable, escopo);
    }
    if(arv->irmao != NULL){
        analise_semantica(arv->irmao, hashtable, escopo);
    }
}

int verificaPalavraReservada(char *lexema){
    if(strcmp(lexema, "if") == 0 || strcmp(lexema, "IF") == 0){
        return 0;
    }
    else if(strcmp(lexema, "while") == 0 || strcmp(lexema, "WHILE") == 0){
        return 0;
    }
    else if(strcmp(lexema, "int") == 0 || strcmp(lexema, "INT") == 0){
        return 0;
    }
    else if(strcmp(lexema, "void") == 0 || strcmp(lexema, "VOID") == 0){
        return 0;
    }
    else if(strcmp(lexema, "null") == 0 || strcmp(lexema, "NULL") == 0){
        return 0;
    }
    else if(strcmp(lexema, "input") == 0 || strcmp(lexema, "INPUT") == 0){
        return 0;
    }
    else if(strcmp(lexema, "output") == 0 || strcmp(lexema, "OUTPUT") == 0){
        return 0;
    }
    else{
        return 1;
    }
}

void errosemantico(char *id, int linha, int monit){
    if(monit == 1){
        printf("-----------------ERRO SEMANTICO-----------------\n");
        printf("ERRO SEMANTICO: %s LINHA: %d\n", id, linha);
        printf("VARIAVEL %s JA DECLARADA\n", id);
        printf("------------------------------------------------\n");
    }
    else if(monit == 2){
        printf("-----------------ERRO SEMANTICO-----------------\n");
        printf("ERRO SEMANTICO: %s LINHA: %d\n", id, linha);
        printf("VARIAVEL %s NAO PODE SER DO TIPO void\n", id);
        printf("------------------------------------------------\n");
    }
    else if(monit == 3){
        printf("-----------------ERRO SEMANTICO-----------------\n");
        printf("ERRO SEMANTICO: %s LINHA: %d\n", id, linha);
        printf("FUNCAO VOID NAO PODE RETORNAR\n", id);
        printf("------------------------------------------------\n");
    }
    else if(monit == 4){
        printf("-----------------ERRO SEMANTICO-----------------\n");
        printf("ERRO SEMANTICO: %s LINHA: %d\n", id, linha);
        printf("VARIAVEL %s NAO DECLARADA\n", id);
        printf("------------------------------------------------\n");
    }
    else if(monit == 5){
        printf("-----------------ERRO SEMANTICO-----------------\n");
        printf("ERRO SEMANTICO: %s LINHA: %d\n", id, linha);
        printf("FUNCAO %s NAO DECLARADA\n", id);
        printf("------------------------------------------------\n");
    }
    exit(1);
}



    


