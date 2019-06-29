#pragma once
#include "Inimigo.h"

namespace Personagens
{

    class InimigoHorneetle : public Inimigo
    {
    public:
        InimigoHorneetle(int posX, int posY);
        ~InimigoHorneetle();

        void andar();
        void movimentar();
        void animar();
    };

}

