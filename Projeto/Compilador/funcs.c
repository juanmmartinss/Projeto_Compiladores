#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "parser.tab.h"


int matriz_dfa[16][21] = {

            /*inicio*/   {2, 3, 16, 16, 16, 16, 16, 16, 16, 16, 16, 4, 12, 8, 10, 9, 16, 16, 16, 1, 18},
            /*letras*/   {2, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18},
                         {17, 3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18},
                         {17, 17, 5, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 18},
                         {5, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},//cometario, lexico ou sintatico?
                         {5, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 7, 5, 5, 5, 5, 5, 5, 5, 5, 5},
                         {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18},
                         {17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 15, 18, 18, 18, 18, 18, 18, 17, 18},
                         {18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 12, 18, 18, 18, 18, 18, 18, 18, 18},
                         {17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 14, 18, 18, 18, 18, 18, 18, 17, 18},
                         {18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 18, 18, 18, 18, 18, 18, 17, 18},
                         {17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 13, 18, 18, 18, 18, 18, 18, 17, 18},
                         {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18},
                         {18, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 18},
                         {18, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 18},
                         {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17},
                         };

// void printa_arvore(No *raiz, int nivel) {
//     if (raiz != NULL) {
//         printa_arvore(raiz->esquerda, nivel + 1);
//         for (int i = 0; i < nivel; i++) {
//             printf("  ");
//         }
//         printf("%s\n", raiz->palavra);
//         printa_arvore(raiz->direita, nivel + 1);
//     }
//     // else {
//     //   printf("Arvore vazia\n");
//     // }
// }

// void chama_printa(){
//   printa_arvore(raiz, 0);
// }

// void chama_desaloca_arvore(){
//   libera_arvore(raiz);
// }


Buffer *allocate_buffer(int size) {
    Buffer *buffer = (Buffer*)malloc(sizeof(Buffer));
    buffer->data = (char*)malloc(sizeof(char) * size);
    if (buffer->data == NULL) {
        fprintf(stderr, "Failed to allocate buffer\n");
        exit(1);
    }
    buffer->size = size; // Definir o tamanho do buffer corretamente
    return buffer;
}

void deallocate_buffer(Buffer *buffer) {
    if (buffer != NULL) { // Verificar se o buffer não é nulo antes de liberar

        free(buffer->data);
        free(buffer);// Liberar o buffer
        buffer = NULL;
    }
    else{
        printf("buffer nulo");
    
    }
}

char* enche_buffer(Buffer *buffer, FILE *arq) {
    memset(buffer->data, '\0', buffer->size);//preenche o buffer com \0, para não ter lixo de memoria
    char *str = fgets(buffer->data, buffer->size, arq);

    // Adiciona um caractere de nova linha fictício ao final do arquivo se necessário
    if (str != NULL && !strchr(buffer->data, '\n') && feof(arq)) {
        buffer->data[strlen(buffer->data)] = '\n';
        str = buffer->data;
    }

    return str;
}


char get_next_char(Buffer *buffer, FILE *arq, Lex *lex) {
  
    if (buffer->pos >= buffer->size) {//verifica se o buffer esta cheio
        if (enche_buffer(buffer, arq) == NULL) {
            return '\0';
        }
        buffer->pos = 0;
    }
    else if(buffer->data[buffer->pos] == '\0'){//verifica se o buffer esta vazio
        if (enche_buffer(buffer, arq) == NULL) {//verifica se o buffer esta vazio
            return '\0';
        }
        lex->linha++;
        buffer->pos = 0;
    }
    

    return buffer->data[buffer->pos++];

}


int pega_valor_para_matriz(char letra){
  int valor;

  if (isdigit(letra) != 0){
    valor = 1;
  }
  else if (isalpha(letra) != 0){
    valor = 0;
  }
  else if (letra == '*'){
    valor = 2;
  }
  else if (letra == '+'){
    valor = 3;
  }
  else if (letra == '-'){
    valor = 4;
  }
  else if (letra == ','){
    valor = 5;
  }
  else if (letra == '{'){
    valor = 6;
  }
  else if (letra == '}'){
    valor = 7;
  }
  else if (letra == '('){
    valor = 8;
  }
  else if (letra == ')'){
    valor = 9;
  }
  else if (letra == ';'){
    valor = 10;
  }
  else if (letra == '/'){
    valor = 11;
  }
  else if (letra == '='){
    valor = 12;
  }
  else if (letra == '<'){
    valor = 13;
  }
  else if (letra == '>'){
    valor = 14;
  }
  else if (letra == '!'){
    valor = 15;
  }
  else if (letra == '['){
    valor = 16;
  }
  else if (letra == ']'){
    valor = 17;
  }
  else if (letra == '.'){
    valor = 18;
  }
  else if (letra == ' ' || letra == '\t' || letra == '\n'){
    valor = 19;
  }
  else{
    valor = 20;
  }

  return valor;
}

int Tabela_DFA(Lex *lex, char letra, Buffer *buffer) {
    int estado = 0;
    int valor = 0;
    int isSpecialChar = 0; // flag para verificar se o caracter é especial, para não armazenar no buffer

    if (lex->estado != 17 && lex->estado != 18) {
        if (lex->estado != 0) {
            estado = lex->estado - 1;
        } else {
            estado = lex->estado;
        }

        valor = pega_valor_para_matriz(letra);

        lex->estado = matriz_dfa[estado][valor];
    }

    isSpecialChar = 0;
    
    if (lex->estado == 17) {
        isSpecialChar = 1;
    }

    if (lex->estado == 18) {
        lex->aux = 1;
        return 1;
    }

    if (!isSpecialChar) {
        if (buffer->pos - 1 < buffer->size) { // Verifica se a posição é válida antes de escrever no buffer
            buffer->data[buffer->pos - 1] = letra;
        } else {
            printf("Erro: Tentando escrever fora dos limites do buffer.\n");
            return -1;
        }
    } else {
        buffer->pos--;
    }

    return isSpecialChar;
}

No* novo_no(char *palavra, TokenType token) {
    No *novo = (No*) malloc(sizeof(No));
    novo->palavra = palavra;
    novo->token = token;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* insere_no(No *raiz, char *palavra, TokenType token) {//insere na arvore
    if (raiz == NULL) {
        return novo_no(palavra, token);
    }
    int cmp = strcmp(palavra, raiz->palavra);
    if (cmp < 0) {
        raiz->esquerda = insere_no(raiz->esquerda, palavra, token);
    } else if (cmp > 0) {
        raiz->direita = insere_no(raiz->direita, palavra, token);
    } else {
        // A palavra já existe na árvore
        free(palavra);
    }
    return raiz;
}

No* busca_no(No *raiz, char *palavra) {//busca na arvore se a palavra é uma palavra reservada
    if (raiz == NULL || strcmp(palavra, raiz->palavra) == 0) {
        return raiz;
    }
    if (strcmp(palavra, raiz->palavra) < 0) {
        return busca_no(raiz->esquerda, palavra);
    } else {
        return busca_no(raiz->direita, palavra);
    }
}

void libera_arvore(No *raiz) {
    if (raiz != NULL) {
        libera_arvore(raiz->esquerda);
        libera_arvore(raiz->direita);
        free(raiz->palavra);
        free(raiz);
    }
}

void Verifica_palavra_reservada(char *palavra, Lex *lex) {
    //static No *raiz = NULL; // Árvore binária de busca balanceada
    if (raiz == NULL) {
        raiz = novo_no("else", ELSE);
        // Inicializa a árvore binária de busca com as palavras reservadas
        raiz = insere_no(raiz, "if", IF);
        raiz = insere_no(raiz, "int", INT);
        raiz = insere_no(raiz, "return", RETURN);
        raiz = insere_no(raiz, "void", VOID);
        raiz = insere_no(raiz, "while", WHILE);
        raiz = insere_no(raiz, "num", NUM);
        //plus
        raiz = insere_no(raiz, "+", PLUS);
        //minus
        raiz = insere_no(raiz, "-", MINUS);
        //times
        raiz = insere_no(raiz, "*", TIMES);
        //over
        raiz = insere_no(raiz, "/", OVER);
        //lt
        raiz = insere_no(raiz, "<", LT);
        //le
        raiz = insere_no(raiz, "<=", LE);
        //gt
        raiz = insere_no(raiz, ">", GT);
        //ge
        raiz = insere_no(raiz, ">=", GE);
        //eq
        raiz = insere_no(raiz, "==", EQ);
        //ne
        raiz = insere_no(raiz, "!=", NE);
        //assign
        raiz = insere_no(raiz, "=", ASSIGN);
        //semi
        raiz = insere_no(raiz, ";", SEMI);
        //comma
        raiz = insere_no(raiz, ",", COMMA);
        //lparen
        raiz = insere_no(raiz, "(", LPAREN);
        //rparen
        raiz = insere_no(raiz, ")", RPAREN);
        //lbracket
        raiz = insere_no(raiz, "[", LBRACKET);
        //rbracket
        raiz = insere_no(raiz, "]", RBRACKET);
        //lbrace
        raiz = insere_no(raiz, "{", LBRACE);
        //rbrace
        raiz = insere_no(raiz, "}", RBRACE);
        
        raiz = insere_no(raiz, "main", MAIN);
        raiz = insere_no(raiz, "printf", PRINTF);

        
    }

    No *no = busca_no(raiz, palavra);
    if (no != NULL) {
        lex->token = no->token;
    } else {
        lex->token = ID;
    }

    //printa_arvore(raiz, 1);

}

void Pega_ID(int valor_letra, Lex *lex, char *pega_carac) {

  if (valor_letra == 0) {
    strcpy(pega_carac, "ELSE");
  } else if (valor_letra == 1) {
    strcpy(pega_carac, "IF");
  } else if (valor_letra == 2) {
    strcpy(pega_carac, "INT");
  } else if (valor_letra == 3) {
    strcpy(pega_carac, "RETURN");
  } else if (valor_letra == 4) {
    strcpy(pega_carac, "VOID");
  } else if (valor_letra == 5) {
    strcpy(pega_carac, "WHILE");
  } else if (valor_letra == 7) {
    strcpy(pega_carac, "NUM");
  } else if (valor_letra == 8) {
    strcpy(pega_carac, "PLUS");
  } else if (valor_letra == 9) {
    strcpy(pega_carac, "MINUS");
  } else if (valor_letra == 10) {
    strcpy(pega_carac, "TIMES");
  } else if (valor_letra == 11) {
    strcpy(pega_carac, "OVER");
  } else if (valor_letra == 12) {
    strcpy(pega_carac, "LT");
  } else if (valor_letra == 13) {
    strcpy(pega_carac, "LE");
  } else if (valor_letra == 14) {
    strcpy(pega_carac, "GT");
  } else if (valor_letra == 15) {
    strcpy(pega_carac, "GE");
  } else if (valor_letra == 16) {
    strcpy(pega_carac, "EQ");
  } else if (valor_letra == 17) {
    strcpy(pega_carac, "NE");
  } else if (valor_letra == 18) {
    strcpy(pega_carac, "ASSIGN");
  } else if (valor_letra == 19) {
    strcpy(pega_carac, "SEMI");
  } else if (valor_letra == 20) {
    strcpy(pega_carac, "COMMA");
  } else if (valor_letra == 21) {
    strcpy(pega_carac, "LPAREN");
  } else if (valor_letra == 22) {
    strcpy(pega_carac, "RPAREN");
  } else if (valor_letra == 23) {
    strcpy(pega_carac, "LBRACKET");
  } else if (valor_letra == 24) {
    strcpy(pega_carac, "RBRACKET");
  } else if (valor_letra == 25) {
    strcpy(pega_carac, "LBRACE");
  } else if (valor_letra == 26) {
    strcpy(pega_carac, "RBRACE");
  } else if (valor_letra == 27) {
    strcpy(pega_carac, "MAIN");
  } else if (valor_letra == 28) {
    strcpy(pega_carac, "PRINTF");
  } else {
    strcpy(pega_carac, "ID");
  }

}
