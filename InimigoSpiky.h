#pragma once
#include "Inimigo.h"

namespace Personagens
{

    class InimigoSpiky : public Inimigo
    {
    public:
        InimigoSpiky(int posX, int posY);
        ~InimigoSpiky();

        void andar();
        void movimentar();
    };

}

