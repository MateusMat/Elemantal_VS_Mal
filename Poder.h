#include "Entidade.h"
#pragma once

class Poder : public Entidade
{
private:
    int id;
    int direcao;
    int cont;

public:
    Poder(float posX, float posY, int dir);
    ~Poder();

    void movimentar();
};
