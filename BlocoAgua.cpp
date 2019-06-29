#include "BlocoAgua.h"

BlocoAgua::BlocoAgua(int tamanhoX, int tamanhoY, int posX, int posY):
Bloco(tamanhoX, tamanhoY, posX, posY)
{
    setTextura("files/Agua.png", 3, 0, 0, true);
}

BlocoAgua::~BlocoAgua()
{

}
