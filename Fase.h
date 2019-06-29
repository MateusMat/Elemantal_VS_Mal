#pragma once
#include "Engine.h"
#include "Jogador.h"
#include "BlocoPlataforma.h"
#include "BlocoEspinho.h"
#include "BlocoAgua.h"
#include "ListaInimigo.h"
#include "ListaEntidade.h"
#include "ListaBloco.h"
#include "InimigoSpiky.h"
#include "InimigoBeorny.h"
#include "InimigoHorneetle.h"
#include "Score.h"
#include "math.h"
#include <vector>
#include <chrono>
#include <iostream>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;
using namespace chrono;


class Fase
{
protected:
    ListaEntidade *listaEntidade;
    ListaBloco *listaBloco;
    ListaInimigo *listaInimigo;
    Engine *motor;

    string tile;
    Music musica;
    int isAlive;

public:
    Fase();
    ~Fase();

    virtual int executar() = 0;
};
