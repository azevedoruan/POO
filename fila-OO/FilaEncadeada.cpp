#include <stdio.h>

class Fila
{
private:
    struct No {
        int valor;
        No* prox;
    };
    No* inicio;
    No* fim;
    int qtde;

public:
    Fila()
    {
        qtde = 0;
        inicio = NULL;
        fim = NULL;
        printf("fila criada\n");
    }

    ~Fila()
    {
        No *aux = inicio;
        No *aux2 = NULL;
        while (aux != NULL)
        {
            aux2 = aux->prox;
            delete aux;
            aux = aux2;
        }

        printf("destruido todos os nos da fila\n");
    }

    int tamanho() {
        return qtde;
    }

    bool inserir(int elemento)
    {
        No* aux = new No;
        aux->valor = elemento;
        aux->prox = NULL;

        if (inicio == NULL) {
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

    bool remover(int *saida)
    {
        if (tamanho() <= 0)
            return false;

        *saida = inicio->valor;
        No* lixo = inicio;
        inicio = inicio->prox;
        delete lixo;
        qtde--;
        return true;
    }
};