#include "Engine.h"

Engine::Engine()
{
    listaEntidade = ListaEntidade::getInstancia();
    listaBloco = ListaBloco::getInstancia();
    listaInimigo = ListaInimigo::getInstancia();
    pontos = Score::getInstancia();

}

Engine::~Engine()
{

}

Engine* Engine::instancia = NULL;

Engine* Engine::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new Engine;
    }
    return instancia;
}

int Engine::executar(Jogador *heroi, bool cameraMov)
{
//    sf::View.setCenter(480, 360);
    camera->setCenter(480, 360);
    listaEntidade->addEntidade(pontos);

    while(janela->isOpen())
    {
        Event evento;
        while (janela->pollEvent(evento))
        {
            if (evento.type == Event::Closed)
                janela->close();

            heroi->lerEvento(evento);
        }

        if(heroi->atacar())
        {
            Poder *temp = new Poder(heroi->getPosX(), heroi->getPosY(), heroi->getOlhandoDireita()? 1 : -1);
            listaEntidade->addEntidade(temp);
            lisP.push_back(temp);
        }

        for(int a = 0; a < listaEntidade->getTamanho(); a++)
        {
            listaEntidade->getEntidade(a)->movimentar();
        }

        for(int i = 0; i < listaBloco->getTamanho(); i++)
        {
            if(colisaoPushBack(heroi, listaBloco->getBloco(i)) && !listaBloco->getBloco(i)->getIsSafe())
            {
                pontos->update(camera, -pontos->getScore());
                return 0;
            }

            for(int p = 0; p < lisP.size(); p++)
            {
                if(colisaoBasica(lisP[p], listaBloco->getBloco(i)))
                {
                    vector<Poder*>::iterator it = lisP.begin() + p;
                    listaEntidade->delEntidade(lisP[p]);
                    lisP.erase(it);
                    p--;
                }
            }

            for(int j = 0; j < listaInimigo->getTamanho(); j++)
            {
                colisaoPushBack(listaInimigo->getInimigo(j), listaBloco->getBloco(i));
            }
        }

        for(int j = 0; j < listaInimigo->getTamanho(); j++)
        {
            if(colisaoBasica(heroi, listaInimigo->getInimigo(j)))
            {
                pontos->update(camera, -pontos->getScore());
                return 0;
            }

            for(int p = 0; p < lisP.size(); p++)
            {
                if(colisaoBasica(lisP[p], listaInimigo->getInimigo(j)))
                {
                    vector<Poder*>::iterator it = lisP.begin() + p;
                    listaEntidade->delEntidade(lisP[p]);
                    lisP.erase(it);

                    if(listaInimigo->getInimigo(j)->dano())
                    {
                        pontos->update(camera, listaInimigo->getInimigo(j)->getValor());
                        listaEntidade->delEntidade(listaInimigo->getInimigo(j));
                        listaInimigo->delInimigo(j);
                    }
                }
            }
        }

        if(heroi->getPosY() > 720)
        {
            pontos->update(camera, -pontos->getScore());
            return 0;
        }



        if(cameraMov)
            centralizarTela(heroi);

        pontos->update(camera, 0);

        janela->setView(*camera);
        janela->clear();
        for(int a = 0; a < listaEntidade->getTamanho(); a++)
        {
            listaEntidade->getEntidade(a)->selfDraw(janela);
        }
        janela->display();

        if(heroi->getPosX() > 9520 || pontos->getScore() >= 5000)
            return 1;
    }
    return -1;
}

void Engine::setJanela(RenderWindow *jan)
{
    janela = jan;
}
void Engine::setCamera(View *cam)
{
    camera = cam;
}

void Engine::centralizarTela(Entidade *Ator)
{
    Vector2f vec = camera->getCenter();
    if(Ator->getPosX() > 480 && Ator->getPosX() < 9120)
    {
        vec = camera->getCenter();
        while(vec.x < Ator->getPosX())
        {
            camera->move(0.1, 0);
            vec = camera->getCenter();
        }
        while(vec.x > Ator->getPosX())
        {
            camera->move(-0.1, 0);
            vec = camera->getCenter();
        }
    }
    if(Ator->getPosX() < 480 && vec.x > 480)
    {
        camera->move(480 - vec.x, 0);
    }
}

bool Engine::colisaoPushBack(Personagem *Ator, Entidade *Objeto)
{
    float aux;
    int i_aux;

    if(Ator->getPosX() + Ator->getTamX() > Objeto->getPosX() && Ator->getPosX() < Objeto->getPosX() + Objeto->getTamX())
        if(Ator->getPosY() + Ator->getTamY() > Objeto->getPosY() && Ator->getPosY() < Objeto->getPosY() + Objeto->getTamY())
        {
            float vec[4] = { Ator->getPosX()   +  Ator->getTamX()   -  Objeto->getPosX() ,
                             Objeto->getPosX() +  Objeto->getTamX() -  Ator->getPosX()   ,
                             Ator->getPosY()   +  Ator->getTamY()   -  Objeto->getPosY() ,
                             Objeto->getPosY() +  Objeto->getTamY() -  Ator->getPosY()   };
            aux = 99;

            for(int i = 0; i < 4; i++)
                if(vec[i] < aux)
                {
                    aux = vec[i];
                    i_aux = i;
                }

            if(i_aux < 2)
            {
                Ator->setAceleracaoX(0);
                Ator->setVelocidadeX(0);
                if(i_aux == 0)
                    Ator->setPosX(Ator->getPosX() - vec[i_aux]);
                else
                    Ator->setPosX(Ator->getPosX() + vec[i_aux]);
            }
            else
            {
                Ator->setAceleracaoY(0);
                Ator->setVelocidadeY(0);
                if(i_aux == 2)
                {
                    Ator->setPosY(Ator->getPosY() - vec[i_aux]);
                    Ator->setContPulo(0);
                }
                else
                    Ator->setPosY(Ator->getPosY() + vec[i_aux]);
            }


            Ator->setPosicaoEnt();
            return true;
        }
    return false;
}

bool Engine::colisaoBasica(Entidade *Ator, Entidade *Objeto)
{
    if(Ator->getPosX() + Ator->getTamX() > Objeto->getPosX() && Ator->getPosX() < Objeto->getPosX() + Objeto->getTamX())
        if(Ator->getPosY() + Ator->getTamY() > Objeto->getPosY() && Ator->getPosY() < Objeto->getPosY() + Objeto->getTamY())
            return true;
    return false;
}

