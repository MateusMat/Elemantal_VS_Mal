#pragma once
#include "Entidade.h"
#include "Lista.h"
#include "Elemento.h"

class ListaEntidade
{
private:
    static ListaEntidade *instancia;

    Lista<Entidade> lista;

protected:
    ListaEntidade();

public:
    ~ListaEntidade();
    static ListaEntidade* getInstancia();

    void addEntidade(Entidade *eA);
    void delEntidade(Entidade *serDeletada);
    Entidade* getEntidade(int pos);
    void limpar();

    int getTamanho();
};
