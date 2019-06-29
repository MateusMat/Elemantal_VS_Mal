#include "InimigoSpiky.h"
using namespace Personagens;

InimigoSpiky::InimigoSpiky(int posX, int posY)
{
    setTamX(46*2);
    setTamY(46*2);

    setPosX(posX*48);
    setPosY(posY*48);

    setGravidade(1.0);
    setInercia(2.0);
    setForcaPulo(0.0);
    setVelMax(10.0);
    setMaxPulo(0);

    valor = 50;

    sprite.setOrigin(23.5, 26);
    setTextura("files/spiky.png", 2, 0, 0, 47, 26, false);
}

InimigoSpiky::~InimigoSpiky()
{

}

void InimigoSpiky::andar()
{
    if(getVelocidadeX() == 0)
        direcao *= -1;

    if(getContAnimacao() %300 > 0 && getContAnimacao() %300 < 50)
        setVelMax(30.0);
    else
        setVelMax(10.0);

    setAceleracaoX(2*direcao);

    sprite.setScale(2*(-direcao), 2);
    setContAnimacao(1 + getContAnimacao());
}

void InimigoSpiky::movimentar()
{
    andar();
    calcMovimentar();
    setPosicaoEnt();


}

