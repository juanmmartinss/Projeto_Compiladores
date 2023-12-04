#ifndef SEMANTICO_H
#define SEMANTICO_H

void inserttree(pont_arv arv, tabelaSimbolos *hashtable, char *escopo);
void inserearvorenaTabela(pont_arv arv, tabelaSimbolos *hashtable, char *escopo);
void declaracao(pont_arv arv, tabelaSimbolos *hashtable, char *escopo);
void expressao(pont_arv arv, tabelaSimbolos *hashtable, char *escopo);
int busca(pont_arv arv, tabelaSimbolos *hashtable, char *escopo, int linha);
tabelaSimbolos* buscanatabela(tabelaSimbolos *hashtable, char *id, char *escopo, Tipo_declaracao tipodeclaracao);
void errosemantico(char *variavelerro, int linha, int monit);
int verificalexema(char *letra);
int verificaSeEfuncao(pont_arv arv, char *escopo);
int buscarnatabelatipo(pont_arv arv, tabelaSimbolos *hashtable, char *escopo, char *lexema);
int verificaPalavraReservada(char *lexema);


#endif