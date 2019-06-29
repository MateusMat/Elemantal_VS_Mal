#pragma once
#include "Bloco.h"
#include <Vector>


class ListaBloco
{
private:
    static ListaBloco *instancia;

    vector<Bloco*> lista;

protected:
    ListaBloco();

public:
    ~ListaBloco();
    static ListaBloco* getInstancia();

    void addBloco(Bloco *bA);
    void delBloco(int pos);
    Bloco* getBloco(int pos);
    void limpar();

    int getTamanho();
};
