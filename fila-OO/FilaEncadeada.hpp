#ifndef PESSOA_H
#define PESSOA_H

#include <string.h>
#include <stdio.h>

class Fila {
private:
    struct No
    {
        No* prox;
        int valor;
    };
    No* inicio;
    No* fim;
    int qtde;
public:
    Fila();
    ~Fila();
    int tamanho();
    bool inserir(int);
    bool remover();
    int primeiroNaFila();
    int ultimoNaFila();
    bool verifica(int);
    bool toString(char*);
};

#endif