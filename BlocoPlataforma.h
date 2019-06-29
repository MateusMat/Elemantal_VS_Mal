#pragma once
#include "Bloco.h"

using namespace sf;

class BlocoPlataforma : public Bloco
{
private:

public:
    BlocoPlataforma(int tamanhoX, int tamanhoY, int posX, int posY, string textura);
    ~BlocoPlataforma();
};

