#include "ListaInimigo.h"

ListaInimigo::ListaInimigo()
{

}

ListaInimigo::~ListaInimigo()
{
    limpar();
}

ListaInimigo* ListaInimigo::instancia = NULL;

ListaInimigo* ListaInimigo::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new ListaInimigo;
    }
    return instancia;
}

int ListaInimigo::addInimigo(Inimigo *iA)
{
    lista.push_back(iA);
}

void ListaInimigo::delInimigo(int pos)
{
    it = lista.begin();

    for (int i = 0; i < pos; i++)
        it++;

    lista.erase(it);
}

Inimigo* ListaInimigo::getInimigo(int pos)
{
    it = lista.begin();

    for (int i = 0; i < pos; i++)
        it++;

    return *it;
}

void ListaInimigo::limpar()
{
    lista.clear();
}

int ListaInimigo::getTamanho()
{
    return lista.size();
}


