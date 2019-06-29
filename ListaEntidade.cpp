#include "ListaEntidade.h"



ListaEntidade::ListaEntidade()
{

}

ListaEntidade::~ListaEntidade()
{
    limpar();
}

ListaEntidade* ListaEntidade::instancia = NULL;

ListaEntidade* ListaEntidade::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new ListaEntidade;
    }
    return instancia;
}

void ListaEntidade::addEntidade(Entidade *eA)
{
    lista.addData(eA);
}

void ListaEntidade::delEntidade(Entidade *serDeletada)
{
    lista.delData(serDeletada);
}

Entidade* ListaEntidade::getEntidade(int pos)
{
    return lista.getData(pos);
}

void ListaEntidade::limpar()
{
    lista.limpar();
}

int ListaEntidade::getTamanho()
{
    return lista.getTamanho();
}

