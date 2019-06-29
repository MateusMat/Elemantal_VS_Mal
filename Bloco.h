#include "Entidade.h"
#include <SFML/Graphics.hpp>
#pragma once

using namespace sf;

class Bloco : public Entidade
{
protected:
    bool isSafe;
public:
    Bloco (int tamanhoX, int tamanhoY, int posX, int posY);
    ~Bloco();

    bool getIsSafe();
};

