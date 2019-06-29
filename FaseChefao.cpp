#include "FaseChefao.h"

FaseChefao::FaseChefao()
{

}

FaseChefao::~FaseChefao()
{

}

int FaseChefao::executar()
{
    musica.openFromFile("files/Musica3.flac");

    listaEntidade->addEntidade(&backgound);
    listaEntidade->addEntidade(&heroi);

    backgound.setTamX(20*48);
    backgound.setTamY(15*48);
    backgound.setTextura("files/background4.png", 6, 0, 0, true);
    tile = "files/tile3.png";

    InimigoHorneetle *temp = new InimigoHorneetle(15, 10);
    listaInimigo->addInimigo(temp);
    listaEntidade->addEntidade(temp);

    for(int i = 0; i < BN; i++)
    {
        BlocoPlataforma *temp = new BlocoPlataforma(layoutBlocos[i][0], layoutBlocos[i][1], layoutBlocos[i][2], layoutBlocos[i][3], tile);
        listaBloco->addBloco(temp);
        listaEntidade->addEntidade(temp);
    }

    musica.play();

    isAlive = motor->executar(&heroi, false);

    musica.stop();

    listaInimigo->limpar();
    listaBloco->limpar();
    listaEntidade->limpar();

    if(isAlive == 1)
        return 3;
    else
        return isAlive-1;
}
