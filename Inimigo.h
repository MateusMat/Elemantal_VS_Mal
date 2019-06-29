#pragma once
#include "Personagem.h"

namespace Personagens
{

    class Inimigo : public Personagem
    {
    protected:
        int direcao;
        int valor;
        int vidas;

    public:
        Inimigo();
        ~Inimigo();

        virtual void andar() = 0;
        virtual void movimentar() = 0;

        int getValor();
        int dano();
    };

}
