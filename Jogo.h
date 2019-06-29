#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Fase1.h"
#include "Fase2.h"
#include "FaseChefao.h"
#include "GerenciadorGrafico.h"
#include "Engine.h"

using namespace sf;
using namespace std;

class Jogo
{
private:
    GerenciadorGrafico gerenciador_grafico;
    Engine *motor;

    Menu menu;

    bool game;
    int alive;

public:
    Jogo();
    ~Jogo();
};
