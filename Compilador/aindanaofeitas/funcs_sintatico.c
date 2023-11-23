#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "global.h"

// pont_arv cria_arvore(char *palavra, int numero_linha){
//     pont_arv raiz = (pont_arv) malloc(sizeof(Arvore));
//     raiz->palavra = palavra;
//     raiz->numero_linha = numero_linha;
//     raiz->filho = NULL;
//     raiz->irmao = NULL;
//     return raiz;
// }

// pont_arv insere_irmao(pont_arv raiz, pont_arv no){
//     if(raiz == NULL){
//         return no;
//     }
//     pont_arv aux = raiz;
//     while(aux->irmao != NULL){
//         aux = aux->irmao;
//     }
//     aux->irmao = no;
//     return raiz;
// }

// pont_arv insere_filho(pont_arv raiz, pont_arv no){
//     if(raiz == NULL){
//         return no;
//     }
//     raiz->filho = no;
//     return raiz;
// }

// void imprime_arvore(pont_arv raiz, int nivel){
//     if(raiz == NULL){
//         return;
//     }
//     int i;
//     for(i = 0; i < nivel; i++){
//         printf("  ");
//     }
//     printf("%s\n", raiz->palavra);
//     imprime_arvore(raiz->filho, nivel+1);
//     imprime_arvore(raiz->irmao, nivel);
// }

// void libera_arvore(pont_arv raiz){
//     if(raiz == NULL){
//         return;
//     }
//     libera_arvore(raiz->filho);
//     libera_arvore(raiz->irmao);
//     free(raiz);
// }

int conversao(int valor){
        if (valor == 0){
            return 258;
        }
        else if (valor == 1){
            return 259;
        }
        else if (valor == 2){
            return 260;
        }
        else if (valor == 3){
            return 261;
        }
        else if (valor == 4){
            return 262;
        }
        else if (valor == 5){
            return 263;
        }
        else if (valor == 6){
            return 264;
        }
        else if (valor == 7){
            return 265;
        }
        else if (valor == 8){
            return 266;
        }
        else if (valor == 9){
            return 267;
        }
        else if (valor == 10){
            return 268;
        }
        else if (valor == 11){
            return 269;
        }
        else if (valor == 12){
            return 270;
        }
        else if (valor == 13){
            return 271;
        }
        else if (valor == 14){
            return 272;
        }
        else if (valor == 15){
            return 273;
        }
        else if (valor == 16){
            return 274;
        }
        else if (valor == 17){
            return 275;
        }
        else if (valor == 18){
            return 276;
        }
        else if (valor == 19){
            return 277;
        }
        else if (valor == 20){
            return 278;
        }
        else if (valor == 21){
            return 279;
        }
        else if (valor == 22){
            return 280;
        }
        else if (valor == 23){
            return 281;
        }
        else if (valor == 24){
            return 282;
        }
        else if (valor == 25){
            return 283;
        }
        else if (valor == 26){
            return 284;
        }
        else if (valor == 27){
            return 285;
        }
        else if (valor == 28){
            return 286;
        }
}