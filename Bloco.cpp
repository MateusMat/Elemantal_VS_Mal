#pragma once
#include "Bloco.h"

Bloco::Bloco(int tamanhoX, int tamanhoY, int posX, int posY)
{
    isSafe = true;
    setTamX(48 * tamanhoX);
    setTamY(48 * tamanhoY);
    setPosX(48 * posX);
    setPosY(48 * posY);
}

Bloco::~Bloco()
{

}

bool Bloco::getIsSafe()
{
    return isSafe;
}
