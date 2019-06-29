#include "Fase.h"

Fase::Fase()
{
    listaEntidade = ListaEntidade::getInstancia();
    listaBloco = ListaBloco::getInstancia();
    listaInimigo = ListaInimigo::getInstancia();
    motor = Engine::getInstancia();

    musica.setLoop(true);
    musica.setVolume(25.f);

    isAlive = 0;
}

Fase::~Fase()
{

}

//bool Fase::Executar()
//{
//
//}
