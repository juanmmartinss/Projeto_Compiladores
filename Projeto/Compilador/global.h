extern int linhaatual;

typedef struct arvore {
    char* tipo;
    char* valor;
    struct arvore* filho;
    struct arvore* irmao;
} Arvore;
