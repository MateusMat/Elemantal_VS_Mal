#include "Inimigo.h"
using namespace Personagens;

Inimigo::Inimigo()
{
    direcao = -1;
    valor = 0;
    vidas = 1;
}

Inimigo::~Inimigo()
{

}

void Inimigo::andar()
{

}

void Inimigo::movimentar()
{

}

int Inimigo::getValor()
{
    return valor;
}

int Inimigo::dano()
{
    vidas--;
    if(vidas <= 0)
        return true;
    return false;
}
