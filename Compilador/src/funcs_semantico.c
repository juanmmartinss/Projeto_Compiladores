#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_simbolos.h"
#include "semantico.h"
#include "parser_arvore.h"
#include <ctype.h>


int buscarnatabela(pont_arv arv, tabelaSimbolos *hashtable, char *escopo, char *lexema){
    int index = hash(lexema);
    tabelaSimbolos list = hashtable[index];

    if(list == NULL){
        return 1;
    }
    else{
        while(list != NULL){
            if(strcmp(list->nameID, lexema) == 0 ){
                if((strcmp(list->escopo, escopo) == 0)||(strcmp(list->escopo, "global") == 0)){
                    return 0;
                }
            }
            list = list->next;
        }
    }
    return 1;
}

int buscarnatabelatipo(pont_arv arv, tabelaSimbolos *hashtable, char *escopo, char *lexema){
    int index = hash(lexema);
    tabelaSimbolos list = hashtable[index];

    if(list == NULL){
        return -1;
    }
    else{
        while(list != NULL){
            if(strcmp(list->nameID, lexema) == 0 ){
                if((strcmp(list->escopo, escopo) == 0)||(strcmp(list->escopo, "global") == 0)){
                    printf("tipo %d \n", list->dataType);
                    return list->dataType;
                }
            }
            list = list->next;
        }
    }
    return -1;
}

void analise_semantica(pont_arv arv, tabelaSimbolos *hashtable, char *escopo)
{

    int controle; int monit; int flag;int controletabela;

    if(arv == NULL){
        return;
    }

    if(arv->tipo == EXPRESSAO){
        printf("EXPRESSAO \n");

        if(arv->tipoexpressao == OPERANDO)
        {
            printf("expressao OPERANDO lexema %s linha %d \n", arv->lexema, arv->linha);
        }
        else if(arv->tipoexpressao == OPERADORRELACIONAL)
        {
            printf("expressao OPERADORRELACIONAL lexema %s linha %d \n", arv->lexema, arv->linha);
        }
        else if(arv->tipoexpressao == CONSTANTE)
        {
            printf("expressao CONSTANTE lexema %s linha %d \n", arv->lexema, arv->linha);
        } 
        else if (arv->tipoexpressao == IDK){
            printf("expressao IDK lexema %s linha %d \n", arv->lexema, arv->linha);
            
            if(controle = buscarnatabela(arv, hashtable, escopo, arv->lexema) == 1){//se nao encontrar o identificador na tabela
                    inserttable(hashtable, arv->tipodeclaracao, arv->tipo, arv->lexema, escopo, arv->linha);
                    controle = 0;
            }
            else{
                inserelinha(hashtable, arv->lexema, arv->linha, escopo);
            }

        } 
        else if (arv->tipoexpressao == CHAMADAFUNCAO){
            if(controle = buscarnatabela(arv, hashtable, escopo, arv->lexema) == 1){//se nao encontrar o identificador na tabela
                    monit = 5;
                    errosemantico(arv->lexema, arv->linha, monit);
            }
            else{
                inserelinha(hashtable, arv->lexema, arv->linha, escopo);
            }
        } 
        else if (arv->tipoexpressao == VETORPARAMETROK){
            printf("expressao VETORPARAMETROK param lexema %s linha %d \n", arv->lexema, arv->linha);
        } 
        else if (arv->tipoexpressao == ATRIBUICAOK){
            printf("expressao ATRIBUICAOK lexema %s linha %d \n", arv->lexema, arv->linha);
            printf("\n filho %s \n", arv->filho1->lexema);
            printf("\n filho %s \n", arv->filho2->lexema);

            printf("\ntipo %d vs %d\n", arv->filho2->tipoexpressao, CHAMADAFUNCAO);

            if(strcmp(arv->filho2->lexema, "input") != 0){
                if(strcmp(arv->filho2->lexema, "output") != 0){
                    if(arv->filho2->tipoexpressao == CHAMADAFUNCAO){
                        controletabela = buscarnatabelatipo(arv, hashtable, escopo, arv->filho1->lexema);
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
        else if (arv->tipoexpressao == NULO){
            printf("expressao NULO lexema %s linha %d \n", arv->lexema, arv->linha);
        } 
        
    } else if (arv->tipo == DECLARACAO){
        printf("DECLARACAO \n");
        if(arv->tipodeclaracao == IFK){

            
            
            printf("declaracao IFK lexema %s linha %d \n", arv->lexema, arv->linha);
            if(arv->linha != 0 ){
                if(controle = buscarnatabela(arv, hashtable, escopo, arv->lexema) == 1){//se nao encontrar o identificador na tabela
                        
                        if(verificaPalavraReservada(arv->lexema) != 0){
                            inserttable(hashtable, arv->tipodeclaracao, arv->tipo, arv->lexema, "global", arv->linha);
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
            printf("declaracao WHILEK lexema %s linha %d \n", arv->lexema, arv->linha);
        }
        else if(arv->tipodeclaracao == INTK){
            printf("declaracao INTK lexema %s linha %d \n", arv->lexema, arv->linha);
            printf("\n filho %s \n", arv->filho1->lexema);
            if(controle = buscarnatabela(arv, hashtable, escopo, arv->filho1->lexema) == 1){//se nao encontrar o identificador na tabela
                    inserttable(hashtable, arv->tipodeclaracao, arv->tipo, arv->filho1->lexema, escopo, arv->linha);
                    controle = 0;
            }
            else{
                //adiciona apenas mais uma linha
                printf("\nadiciona linha %d\n", arv->linha);
                inserelinha(hashtable, arv->filho1->lexema, arv->linha, "global");

            }
        }
        else if(arv->tipodeclaracao == VOIDK){
            printf("declaracao VOIDK  lexema %s linha %d \n", arv->lexema, arv->linha);
        }
        else if(arv->tipodeclaracao == NULOK){
            printf("declaracao NULOK lexema %s linha %d \n", arv->lexema, arv->linha);
        }
        else if(arv->tipodeclaracao == VARIAVELK){
            printf("declaracao VARIAVELK lexema %s linha %d \n", arv->lexema, arv->linha);
            
            if(strcmp(arv->lexema, "VOID") == 0){
                monit = 2;
                errosemantico(arv->filho1->lexema, arv->linha, monit);
            }

            if(controle = buscarnatabela(arv, hashtable, escopo, arv->filho1->lexema) == 1){//se nao encontrar o identificador na tabela
                    inserttable(hashtable, arv->tipodeclaracao, arv->tipo, arv->filho1->lexema, escopo, arv->linha);
                    controle = 0;
            }
            else{
                //printf("entra aqui");
                monit = 1;
                errosemantico(arv->filho1->lexema, arv->linha, monit);
            }
                

        }else if(arv->tipodeclaracao == VETORK)
        {
            printf("declaracao VETORK lexema %s linha %d \n", arv->lexema, arv->linha);
        }else if(arv->tipodeclaracao == FUNCAOK)
        {
            printf("declaracao FUNCAOK lexema %s linha %d \n", arv->lexema, arv->linha);
            //printf("\n filho %s \n", arv->filho2->lexema);
            escopo = arv->filho2->lexema;

        }else if(arv->tipodeclaracao == PARAMETROVARIAVELK)
        {
            printf("declaracao PARAMETROVARIAVELK lexema %s linha %d \n", arv->lexema, arv->linha);

            //printf("\n filho %s \n", arv->filho1->lexema);

            if(controle = buscarnatabela(arv, hashtable, escopo, arv->filho1->lexema) == 1){//se nao encontrar o identificador na tabela
                    inserttable(hashtable, arv->tipodeclaracao, arv->tipo, arv->filho1->lexema, escopo, arv->linha);
                    controle = 0;
            }

        }
        else if(arv->tipodeclaracao == PARAMETROVETORK){
            printf("declaracao PARAMETROVETORK lexema %s linha %d \n", arv->lexema, arv->linha);
        }
        else if(arv->tipodeclaracao == PARAMETROVOIDK){
            printf("declaracao PARAMETROVOIDK lexema %s linha %d \n", arv->lexema, arv->linha);
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



    


