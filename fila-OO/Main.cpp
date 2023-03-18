#include "FilaEncadeada.hpp"

int main()
{
    Fila *f1 = new Fila;
    printf("\ninserido valor 20 na fila: %d\n", f1->inserir(20));
    printf("inserido valor 30 na fila: %d\n", f1->inserir(30));
    printf("inserido valor 40 na fila: %d\n", f1->inserir(40));
    printf("inserido valor 50 na fila: %d\n", f1->inserir(50));
    printf("inserido valor 60 na fila: %d\n", f1->inserir(60));
    char string[100];
    f1->toString(string);
    printf(string);
    printf("remover primeiro da fila: %d\n", f1->remover());
     f1->toString(string);
    printf(string);
    printf("primeiro da fila %d\n", f1->primeiroNaFila());
    printf("ultimo da fila %d\n", f1->ultimoNaFila());
    printf("existe o numero 50 na fila?: %d\n", f1->verifica(50));
    printf("existe o numero 10 na fila?: %d\n\n", f1->verifica(10));
    delete f1;

    return 0;
}