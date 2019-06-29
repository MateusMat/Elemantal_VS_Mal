#include "Jogador.h"
using namespace Personagens;

Jogador::Jogador()
{
    setTamX(30*2);
    setTamY(55*2);

    setPosX(1*48);
    setPosY(13*48);

    setGravidade(1.0);
    setInercia(2.0);
    setForcaPulo(20.0);
    setVelMax(10.0);
    setMaxPulo(2);

    sprite.setOrigin(40, 70);

    setTextura("files/Sorlo.png", 2, 0, 0, 79, 79, false);

    ataqueFogo = false;
//    ataqueRaio = false;
}
Jogador::~Jogador()
{

}

void Jogador::andar()
{
    if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        setAceleracaoX(-1.5);
        setOlhandoDireita(false);
    }

    else if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        setAceleracaoX(1.5);
        setOlhandoDireita(true);
    }
    else
        setAceleracaoX(0);
}

void Jogador::lerEvento(Event event)
{
    if(getContPulo() < getMaxPulo())
    {
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Up)
        {
            setVelocidadeY(-getForcaPulo());
            setContPulo(getContPulo() + 1);
            setContAnimacao(0);
        }
    }
    if(!(ataqueFogo || ataqueRaio) && event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
    {
        ataqueFogo = true;
        setContAnimacao(0);
    }
//    if(!(ataqueFogo || ataqueRaio) && event.type == Event::KeyPressed && event.key.code == Keyboard::X)
//    {
//        ataqueRaio = true;
//        setContAnimacao(0);
//    }
}

bool Jogador::atacar()
{
    if(ataqueFogo && getContAnimacao() == 24)
    {
        return true;
    }
    return false;
}

void Jogador::movimentar()
{
    andar();
    calcMovimentar();
    setPosicaoEnt();
    animar();
}

void Jogador::animar()
{
    if(getOlhandoDireita())
        sprite.setScale(2, 2);
    else
        sprite.setScale(-2, 2);

    if(ataqueFogo)
    {
        if(getContAnimacao()%6 == 0)
            {
                animacao.top = 160;
                animacao.left = 80 * ((getContAnimacao()%36) / 6);
            }
        else if(getContAnimacao() > 36)
            ataqueFogo = false;
    }

//    else if(ataqueRaio)
//    {
//        if(getContAnimacao()%6 == 0)
//            {
//                animacao.top = 240;
//                animacao.left = 80 * ((getContAnimacao()%30) / 6);
//            }
//        else if(getContAnimacao() > 30)
//            ataqueRaio = false;
//    }

    else if(getVelocidadeY() <= 0)
    {
        animacao.top = 80;
        animacao.left = 320;
    }

    else
    {
        if(getAceleracaoX() == 0)
            animacao.top = 0;
        else
            animacao.top = 80;

        if(getContAnimacao()%10 == 0)
        {
            animacao.left =(((getContAnimacao()%40) / 10) * 80);
        }
    }

    setContAnimacao(getContAnimacao() + 1);
    sprite.setTextureRect(animacao);
}


