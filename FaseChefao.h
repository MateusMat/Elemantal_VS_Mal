#pragma once
#include "Fase.h"
#include "InimigoHorneetle.h"
#define BN 3

class FaseChefao : public Fase
{
private:
    Jogador heroi;
    Entidade backgound;

    int layoutBlocos[BN][4] = { { 20,   1,  0,   14},
                                {  1,  25,  -1, -10},
                                {  1,  25, 20, -10}};
public:
    FaseChefao();
    ~FaseChefao();

    int executar();
};
