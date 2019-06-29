#include "Jogo.h"

Jogo::Jogo()
{
    motor = Engine::getInstancia();
    motor->setJanela(gerenciador_grafico.getJanela());
    motor->setCamera(gerenciador_grafico.getCamera());

    game = true;
    alive = -1;

    while(game)
    {
        if(alive == -1)
            alive = menu.executar(gerenciador_grafico.getJanela(), gerenciador_grafico.getCamera());
        if(alive == 0)
        {
            Fase1   fase_1;
            alive = fase_1.executar();
        }
        if(alive == 1)
        {
            Fase2   fase_2;
            alive = fase_2.executar();
        }
        if(alive == 2)
        {
            FaseChefao fase_3;
            alive = fase_3.executar();
        }
        if(alive == 3 || alive == -2)
            game = false;
    }
}

Jogo::~Jogo()
{

}


