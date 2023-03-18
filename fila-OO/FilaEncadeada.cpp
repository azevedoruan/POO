#include "FilaEncadeada.hpp"

Fila::Fila()
{
    qtde = 0;
    inicio = NULL;
    fim = NULL;
}

Fila::~Fila()
{
    No *aux = inicio;
    No *aux2 = NULL;
    while (aux != NULL)
    {
        aux2 = aux->prox;
        delete aux;
        aux = aux2;
    }
}

int Fila::tamanho()
{
    return qtde;
}

bool Fila::inserir(int elemento)
{
    No *aux = new No;
    aux->valor = elemento;
    aux->prox = NULL;

    if (inicio == NULL)
    {
        inicio = aux;
        fim = aux;
        qtde++;
        return true;
    }

    fim->prox = aux;
    fim = aux;
    qtde++;
    return true;
}

bool Fila::remover()
{
    if (tamanho() <= 0)
        return false;

    No *lixo = inicio;
    inicio = inicio->prox;
    delete lixo;
    qtde--;
    return true;
}

int Fila::primeiroNaFila()
{
    return inicio->valor;
}

int Fila::ultimoNaFila()
{
    return fim->valor;
}

bool Fila::verifica(int valor)
{
    No *aux = inicio;
    while (aux != NULL)
    {
        if (aux->valor == valor)
            return true;

        aux = aux->prox;
    }
    return false;
}

bool Fila::toString(char *str)
{
    if (tamanho() <= 0)
        return false;

    str[0] = '\0';
    strcat(str, "[");
    No *aux = inicio;
    char strAux[50];
    int i = 0;
    while (aux != NULL)
    {
        sprintf(strAux, "%d", aux->valor);
        strcat(str, strAux);
        aux = aux->prox;
        if (i < tamanho() - 1)
            strcat(str, ",");
        i++;
    }
    strcat(str, "]\n");

    return true;
}