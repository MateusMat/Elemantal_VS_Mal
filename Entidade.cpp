#include "Entidade.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Entidade::Entidade()
{
    posX = 0.0;
    posY = 0.0;
    tamX = 0.0;
    tamY = 0.0;
    velocidadeX = 0.0;
    velocidadeY = 0.0;
}

Entidade::~Entidade()
{

}

void Entidade::selfDraw(RenderWindow *window)
{
    window->draw(sprite);
}

void Entidade::movimentar()
{

}

void Entidade::setTextura (string tx, int escala, int imgX, int imgY, /*int imgTamX, int imgTamY,*/ bool seRepete)
{
    textura.loadFromFile(tx);
    textura.setRepeated(seRepete);


    animacao.left = imgX;
    animacao.top = imgY;
    animacao.width = getTamX() / escala;
    animacao.height = getTamY() / escala;


    sprite.setTexture(textura);
    sprite.setScale(escala, escala);
    sprite.setTextureRect(animacao);

    sprite.setPosition(posX, posY);
}

void Entidade::setTextura (string tx, int escala, int imgX, int imgY, int imgTamX, int imgTamY, bool seRepete)
{
    textura.loadFromFile(tx);
    textura.setRepeated(seRepete);


    animacao.left = imgX;
    animacao.top = imgY;
    animacao.width = imgTamX;
    animacao.height = imgTamY;


    sprite.setTexture(textura);
    sprite.setScale(escala, escala);
    sprite.setTextureRect(animacao);

    sprite.setPosition(posX + tamX/2, posY + tamY);
}

void Entidade::setAnimacao(int newImgPosX, int newImgPosY, int newImgTamX, int newImgTamY)
{
    animacao.left = newImgPosX;
    animacao.top = newImgPosY;
    animacao.width = newImgTamX;
    animacao.height = newImgTamY;

    sprite.setTextureRect(animacao);
}

void Entidade::setPosicaoEnt()
{
    sprite.setPosition(posX + tamX/2, posY + tamY);
}

void Entidade::setPosX (float pX){posX = pX;}
float Entidade::getPosX (){return posX;}

void Entidade::setPosY (float pY){posY = pY;}
float Entidade::getPosY (){return posY;}

void Entidade::setTamX (float tX){tamX = tX;}
float Entidade::getTamX (){return tamX;}

void Entidade::setTamY (float tY){tamY = tY;}
float Entidade::getTamY (){return tamY;}


