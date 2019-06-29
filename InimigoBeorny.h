#pragma once
#include "Inimigo.h"

namespace Personagens
{

    class InimigoBeorny : public Inimigo
    {
    private:
        int wings;

    public:
        InimigoBeorny(int posX, int posY);
        ~InimigoBeorny();

        void andar();
        void movimentar();
    };

}

