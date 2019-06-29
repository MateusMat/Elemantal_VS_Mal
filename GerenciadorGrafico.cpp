#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico()
{
    janela = new RenderWindow(VideoMode(960, 720), "Elemental contra as forças do mal");
    camera = new View(Vector2f(480.f, 360.f), Vector2f(960.f, 720.f));

    janela->setVerticalSyncEnabled(true);
//    janela->setFramerateLimit(2);
    janela->setKeyRepeatEnabled(false);
}

GerenciadorGrafico::~GerenciadorGrafico()
{

}

RenderWindow* GerenciadorGrafico::getJanela()
{
    return janela;
}

View* GerenciadorGrafico::getCamera()
{
    return camera;
}
