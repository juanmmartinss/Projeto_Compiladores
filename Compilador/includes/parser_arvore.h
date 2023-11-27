#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arvore{
    struct Arvore *filho;
    struct Arvore *irmao;
    char *palavra;
    int numero_linha;
}Arvore;

typedef Arvore *pont_arv;


pont_arv cria_arvore(char *palavra, int numero_linha);
pont_arv insere_irmao(pont_arv raiz, pont_arv no);
pont_arv insere_filho(pont_arv raiz, pont_arv no);
void imprime_arvore(pont_arv raiz, int nivel);
void libera_arvore(pont_arv raiz);
