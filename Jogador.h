#pragma once
#include "Personagem.h"

namespace Personagens
{

    class Jogador : public Personagem
    {
    private:
    //    int vidas;

        bool ataqueFogo;
        bool ataqueRaio;

    protected:
        void andar();

    public:
        Jogador();
        ~Jogador();

        void animar();
        void setPosJogador();
        void lerEvento(Event event);
        bool atacar();
        void movimentar();
    };

}

