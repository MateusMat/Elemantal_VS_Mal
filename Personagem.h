#pragma once
#include "Entidade.h"

namespace Personagens
{

    class Personagem : public Entidade
    {
    private:
    //    bool isAlive;

        float velocidadeX;
        float velocidadeY;
        float aceleracaoX;
        float aceleracaoY;
        float velMax;
        float inercia;
        float forcaPulo;
        float gravidade;

        int maxPulo;
        int contPulo;
        int contAnimacao;

        bool olhandoDireita;

    protected:

        void calcMovimentar();

        void  setVelMax (float vm);
        float getVelMax ();

        void  setInercia (float in);
        float getInercia ();

        void  setForcaPulo (float fp);
        float getForcaPulo ();

        void  setGravidade (float g);
        float getGravidade ();

        void  setMaxPulo (int mP);
        int   getMaxPulo ();

        void  setContAnimacao (int cA);
        int   getContAnimacao ();

    public:
        Personagem();
        ~Personagem();

        virtual void movimentar() = 0;

        void  setVelocidadeX (float vX);
        float getVelocidadeX ();

        void  setVelocidadeY (float vY);
        float getVelocidadeY ();

        void  setAceleracaoX (float aX);
        float getAceleracaoX ();

        void  setAceleracaoY (float aY);
        float getAceleracaoY ();

        void  setContPulo (int cP);
        int   getContPulo ();

        void  setOlhandoDireita (bool oD);
        bool  getOlhandoDireita ();
    };

}
