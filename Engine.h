#pragma once
#include "ListaEntidade.h"
#include "ListaBloco.h"
#include "ListaInimigo.h"
//#include "Entidade.h"
//#include "Personagem.h"
#include "Jogador.h"
#include "Bloco.h"
#include "Poder.h"
#include "vector"
#include "Score.h"
#include <SFML/Graphics.hpp>

class Engine
{
private:
    static Engine *instancia;
    RenderWindow *janela;
    View *camera;
    Score *pontos;

    vector<Poder*> lisP;

    ListaEntidade *listaEntidade;
    ListaBloco *listaBloco;
    ListaInimigo *listaInimigo;

protected:
    Engine();

public:
    ~Engine();
    static Engine* getInstancia();

    int executar(Jogador *heroi, bool cameraMov);

    void setJanela(RenderWindow *jan);
    void setCamera(View *cam);

    bool colisaoPushBack(Personagem *Ator, Entidade *Objeto);
    bool colisaoBasica(Entidade *Ator, Entidade *Objeto);
    void centralizarTela(Entidade *Ator);
};
