#include "Score.h"

Score::Score()
{
    pontuacao = 0;

    fonte.loadFromFile("files/pixel.ttf");
    texto.setFont(font);
    texto.setCharacterSize(40);
    texto.setPosition(15.f, 15.f);
    font.loadFromFile("files/pixel.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setString("Score");
}

Score* Score::instancia = NULL;

Score* Score::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new Score;
    }
    return instancia;
}

Score::~Score()
{

}

void Score::selfDraw(RenderWindow *window)
{
    window->draw(texto);
    window->draw(text);
}

void Score::update(View *janela, int pontos)
{
    pontuacao += pontos;
    texto.setString(to_string(pontuacao));
    Vector2f vec;
    Vector2f vec2;
    vec = janela->getCenter();
    vec.x -= 420;
    vec.y -= 360;
    texto.setPosition(vec);
    texto.setColor(Color::Yellow);
    vec2 = janela->getCenter();
    vec2.x -= 480;
    vec2.y -= 348;
    text.setPosition(vec2);
    text.setColor(Color::Black);
}

int Score::getScore()
{
    return pontuacao;
}
