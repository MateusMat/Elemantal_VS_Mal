#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#pragma once

using namespace sf;
using namespace std;


class Entidade
{
private:
    float posX;
    float posY;
    float tamX;
    float tamY;
    float velocidadeX;
    float velocidadeY;

protected:
    Sprite sprite;
    Texture textura;
    IntRect animacao;

    void setAnimacao (int newImgPosX, int newImgPosY, int newImgTamX, int newImgTamY);

public:
    Entidade();
    ~Entidade();

    Sprite getSprite();
    virtual void selfDraw(RenderWindow *window);

    virtual void movimentar();

    void setTextura (string tx, int escala, int imgX, int imgY, bool seRepete);
    void setTextura (string tx, int escala, int imgX, int imgY, int imgTamX, int imgTamY, bool seRepete);
    void setPosicaoEnt ();

    void setPosX (float pX);
    float getPosX ();

    void setPosY (float pY);
    float getPosY ();

    void setTamX (float tX);
    float getTamX ();

    void setTamY (float tY);
    float getTamY ();

};
