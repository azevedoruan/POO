#include "FilaEncadeada.cpp"

int main()
{
    Fila *f1 = new Fila;
    printf("inserido na lista %d\n", f1->inserir(20));
    int valorRemovido;
    bool removido = f1->remover(&valorRemovido);
    printf("removido valor %d da fila %d\n", valorRemovido, removido);
    delete f1;

    return 0;
}