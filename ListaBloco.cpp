#include "ListaBloco.h"

ListaBloco::ListaBloco()
{

}

ListaBloco::~ListaBloco()
{
    limpar();
}

ListaBloco* ListaBloco::instancia = NULL;

ListaBloco* ListaBloco::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new ListaBloco;
    }
    return instancia;
}

void ListaBloco::addBloco(Bloco *bA)
{
    lista.push_back(bA);
}

void ListaBloco::delBloco(int pos)
{
    vector<Bloco*>::iterator it = lista.begin() + pos;

    delete lista[pos];

    lista.erase(it);
}

Bloco* ListaBloco::getBloco(int pos)
{
    return lista[pos];
}

void ListaBloco::limpar()
{
    lista.clear();
}

int ListaBloco::getTamanho()
{
    return lista.size();
}

