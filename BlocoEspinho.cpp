#include "BlocoEspinho.h"

BlocoEspinho::BlocoEspinho(int tamanhoX, int tamanhoY, int posX, int posY, int rotacao):
Bloco(tamanhoX, tamanhoY, posX, posY)
{
    isSafe = false;
    setTextura(pathFile[rotacao], 1, 0, 0, true);
}

BlocoEspinho::~BlocoEspinho()
{

}
