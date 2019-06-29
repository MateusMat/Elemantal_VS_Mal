#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class GerenciadorGrafico
{
private:
    RenderWindow *janela;
    View *camera;

public:
    GerenciadorGrafico();
    ~GerenciadorGrafico();

    RenderWindow* getJanela();
    View* getCamera();
};

