#include "Poder.h"

Poder::Poder(float posX, float posY, int dir)
{


    direcao = dir;
    cont = 0;
    setTamX(17*2);
    setTamY(20*2);

    setPosX(posX + 15 + (95*direcao));
    setPosY(posY - 0);

    sprite.setOrigin(40, 40);

    setTextura("files/Sorlo.png", 2*direcao, 80*10, 80*2, 79, 79, false);
}

Poder::~Poder()
{

}

void Poder::movimentar()
{
    setPosX(getPosX() + 10*direcao);
    setPosicaoEnt();
    if(cont < 12)
    {
        animacao.left = 80*6;
    }
    else if(cont%12 == 0)
        animacao.left = 80*7;
    else if(cont%12 == 4)
        animacao.left = 80*8;
    else if(cont%12 == 8)
        animacao.left = 80*9;

    cont++;
    sprite.setTextureRect(animacao);
}
