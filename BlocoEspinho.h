#pragma once
#include "Bloco.h"

using namespace sf;

class BlocoEspinho : public Bloco
{
private:
    string pathFile[4] = {  "files/Espinho0.png" ,
                            "files/Espinho1.png" ,
                            "files/Espinho2.png" ,
                            "files/Espinho3.png" ,};

public:
    BlocoEspinho(int tamanhoX, int tamanhoY, int posX, int posY, int rotacao);
    ~BlocoEspinho();
};

