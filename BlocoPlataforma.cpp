#include "BlocoPlataforma.h"

BlocoPlataforma::BlocoPlataforma(int tamanhoX, int tamanhoY, int posX, int posY, string textura):
Bloco(tamanhoX, tamanhoY, posX, posY)
{
    setTextura(textura, 3, 0, 0, true);
}

BlocoPlataforma::~BlocoPlataforma()
{

}
