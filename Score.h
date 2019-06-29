#pragma once
#include "Entidade.h"
#include <SFML/Graphics.hpp>

class Score : public Entidade
{
private:
    static Score *instancia;

    int pontuacao;
    Font fonte;
    Font font;
    Text texto;
    Text text;

protected:
    Score();

public:
    ~Score();
    static Score* getInstancia();

    void selfDraw(RenderWindow *window);
    void update(View *janela, int pontos);

    int getScore();
};
