#pragma once
#include "Inimigo.h"
#include <list>
#include <iterator>

using namespace Personagens;

class ListaInimigo
{
private:
    static ListaInimigo *instancia;

    list<Inimigo*> lista;
    list<Inimigo*>::iterator it;

protected:
    ListaInimigo();

public:
    ~ListaInimigo();
    static ListaInimigo* getInstancia();

    int addInimigo(Inimigo *iA);
    void delInimigo(int pos);
    Inimigo* getInimigo(int pos);
    void limpar();

    int getTamanho();
};
