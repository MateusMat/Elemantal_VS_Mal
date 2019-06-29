#include "InimigoBeorny.h"
using namespace Personagens;

InimigoBeorny::InimigoBeorny(int posX, int posY)
{
    setTamX(20*2);
    setTamY(18*2);

    setPosX(posX*48);
    setPosY(posY*48);

    setGravidade(0.0);
    setInercia(1.0);
    setForcaPulo(0.0);
    setVelMax(10.0);
    setMaxPulo(0);

    valor = 30;

    wings = 1;
    sprite.setOrigin(11.5, 9.5);
    setTextura("files/Beorny.png", 2, 0, 0, 24, 20, false);
}

InimigoBeorny::~InimigoBeorny()
{

}

void InimigoBeorny::andar()
{
    if(getContAnimacao() % 4 == 0)
    {
        animacao.left += 24*wings;
        wings *= -1;
    }

    if(getContAnimacao() % 50 == 0)
    {
        setVelocidadeY(5 * direcao);
        direcao *= -1;
    }

    sprite.setTextureRect(animacao);
    setContAnimacao(1 + getContAnimacao());
}

void InimigoBeorny::movimentar()
{
    andar();
    calcMovimentar();
    setPosicaoEnt();
}

