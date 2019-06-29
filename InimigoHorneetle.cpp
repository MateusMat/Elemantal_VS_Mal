#include "InimigoHorneetle.h"
using namespace Personagens;

InimigoHorneetle::InimigoHorneetle(int posX, int posY)
{
    setTamX(100*2);
    setTamY(100*2);

    setPosX(posX*48);
    setPosY(posY*48);

    setGravidade(3.0);
    setInercia(5.0);
    setForcaPulo(30.0);
    setVelMax(25.0);
    setMaxPulo(1);

    valor = 5000;
    vidas = 15;

    sprite.setOrigin(73, 126);
    setTextura("files/Horneetle.png", 2, 0, 0, 150, 150, false);
}

InimigoHorneetle::~InimigoHorneetle()
{

}

void InimigoHorneetle::andar()
{
    int aux = getContAnimacao()%851;

    if(aux == 100)
        setAceleracaoX(2*direcao);
    else if(aux == 170)
        direcao *= -1;
    else if(aux == 270)
        setAceleracaoX(2*direcao);
    else if(aux == 340)
        direcao *= -1;
    else if(aux == 440)
        setVelocidadeX(25*direcao);
    else if(aux == 490)
        direcao *= -1;
    else if(aux == 540)
    {
        setVelocidadeX(25*direcao);
        setVelocidadeY(-55);
    }
    else if(aux == 590)
        direcao *= -1;
    else if(aux == 690)
        setAceleracaoX(4*direcao);
    else if(aux == 730)
        direcao *= -1;
    else if(aux == 750)
        setAceleracaoX(4*direcao);
    else if(aux == 790)
        direcao *= -1;
    else if(aux == 810)
        setAceleracaoX(4*direcao);
    else if(aux == 850)
        direcao *= -1;
}

void InimigoHorneetle::movimentar()
{
    andar();
    calcMovimentar();
    setPosicaoEnt();
    animar();
}

void InimigoHorneetle::animar()
{
    sprite.setScale(2*direcao, 2);

        if(getVelocidadeX() == 0)
        {
            animacao.top = 0;
            if(getContAnimacao()%6 == 0)
            {
                animacao.left = 150*(getContAnimacao()%30/6);
            }
        }
        else
        {
            animacao.top = 150;
            if(getContAnimacao()%4 == 0)
            {
                animacao.left = 150*(getContAnimacao()%28/4);
            }
        }

    setContAnimacao(getContAnimacao() + 1);
    sprite.setTextureRect(animacao);
}
