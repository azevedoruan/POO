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

    bool remover()
    {
        if (tamanho() <= 0)
            return false;

        No* lixo = inicio;
        inicio = inicio->prox;
        delete lixo;
        qtde--;
        return true;
    }

    int primeiroNaFila()
    {
        return inicio->valor;
    }

    int ultimoNaFila()
    {
        return fim->valor;
    }

    // TODO
    /*bool verifica(int valor)
    {
        

        No* aux = inicio;
        while (aux != NULL)
        {

        }
    }*/
};