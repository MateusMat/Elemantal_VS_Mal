#include "Personagem.h"
using namespace Personagens;

Personagem::Personagem()
{
    velocidadeX = 0.0;
    velocidadeY = 0.0;
    aceleracaoX = 0.0;
    aceleracaoY = 0.0;

    velMax = 0.0;
    inercia = 0.0;
    forcaPulo = 0.0;
    gravidade = 0.0;
    maxPulo = 0;
    contPulo = 0;
    contAnimacao = 0;
    olhandoDireita = true;
}

Personagem::~Personagem()
{

}

void Personagem::movimentar()
{

}

void Personagem::calcMovimentar()
{
    velocidadeY += gravidade;

    velocidadeX += (aceleracaoX / inercia);
    velocidadeY += (aceleracaoY / inercia);

    if (velocidadeX > 0 && aceleracaoX == 0)
        velocidadeX -= 1 / inercia;
    else if (velocidadeX < 0 && aceleracaoX == 0)
        velocidadeX += 1 / inercia;

    if(velocidadeX > velMax)
        velocidadeX = velMax;
    else if (velocidadeX < -velMax)
        velocidadeX = - velMax;

    setPosX(getPosX() + velocidadeX);
    setPosY(getPosY() + velocidadeY);
}


void  Personagem::setVelocidadeX    (float vX) {velocidadeX = vX;}
float Personagem::getVelocidadeX    () {return velocidadeX;}

void  Personagem::setVelocidadeY    (float vY) {velocidadeY = vY;}
float Personagem::getVelocidadeY    () {return velocidadeY;}

void  Personagem::setAceleracaoX    (float aX) {aceleracaoX = aX;}
float Personagem::getAceleracaoX    () {return aceleracaoX;}

void  Personagem::setAceleracaoY    (float aY) {aceleracaoY = aY;}
float Personagem::getAceleracaoY    () {return aceleracaoY;}

void  Personagem::setVelMax         (float vm) {velMax = vm;}
float Personagem::getVelMax         () {return velMax;}

void  Personagem::setInercia        (float in) {inercia = in;}
float Personagem::getInercia        () {return inercia;}

void  Personagem::setForcaPulo      (float fp) {forcaPulo = fp;}
float Personagem::getForcaPulo      () {return forcaPulo;}

void  Personagem::setGravidade      (float g) {gravidade = g;}
float Personagem::getGravidade      () {return gravidade;}

void  Personagem::setMaxPulo        (int mP) {maxPulo = mP;}
int   Personagem::getMaxPulo        () {return maxPulo;}

void  Personagem::setContPulo       (int cP) {contPulo = cP;}
int   Personagem::getContPulo       () {return contPulo;}

void  Personagem::setContAnimacao   (int cA){contAnimacao = cA;}
int   Personagem::getContAnimacao   () {return contAnimacao;}

void  Personagem::setOlhandoDireita (bool oD){olhandoDireita = oD;}
bool  Personagem::getOlhandoDireita () {return olhandoDireita;}
