#pragma once
#include "Elemento.h"

template<class TIPO>
class Lista
{
private:
    Elemento<TIPO> *first;
    Elemento<TIPO> *last;
    int tamanho;

public:
    Lista ();
    ~Lista ();

    Elemento<TIPO>* getPrimeiro();
    Elemento<TIPO>* getAtual();
    int getTamanho();

    void  addData (TIPO* data);
    void  delData (TIPO* data);
    TIPO* getData (int pos);

    void limpar();
};

template<class TIPO>
Lista<TIPO>::Lista ()
{
    first = NULL;
    last = NULL;
    tamanho = 0;
}

template<class TIPO>
Lista<TIPO>::~Lista ()
{
    limpar();
}

template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::getPrimeiro()
{
    return first;
}

template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::getAtual()
{
    return last;
}

template<class TIPO>
int Lista<TIPO>::getTamanho()
{
    return tamanho;
}

template<class TIPO>
void Lista<TIPO>::addData (TIPO *data)
{
    Elemento<TIPO>* pElemento = new Elemento<TIPO>();
    pElemento->setData(data);

    if (first == NULL)
    {
        first = pElemento;
        first->setPrev(NULL);
        first->setNext(NULL);
        last = first;
    }
    else
    {
        pElemento->setPrev (last);
        pElemento->setNext (NULL);
        last->setNext (pElemento);
        last = last->getNext ();
    }
    tamanho++;
}

template<class TIPO>
void Lista<TIPO>::delData (TIPO* data)
{
    Elemento<TIPO> *aux = first;

    while(aux->getData() != data)
        aux = aux->getNext();

    if(first == aux && last == aux)
    {
        first = NULL;
        last = NULL;
    }
    if(first == aux)
    {
        first = aux->getNext();
        first->setPrev(NULL);
    }
    else if(last == aux)
    {
        last = aux->getPrev();
        last->setNext(NULL);
    }
    else
    {
        aux->getNext()->setPrev(aux->getPrev());
        aux->getPrev()->setNext(aux->getNext());
    }

//    aux->delData();
    delete aux;
    tamanho--;
}

template<class TIPO>
TIPO* Lista<TIPO>::getData (int pos)
{
    Elemento<TIPO> *aux = first;

    int i = 0;

    while(aux != NULL && i < pos)
    {
        aux = aux->getNext();
        i++;
    }

    return aux->getData();
}

template<class TIPO>
void Lista<TIPO>::limpar()
{
    Elemento<TIPO> *aux = first;
    Elemento<TIPO> *aux2;

    while (aux != last)
    {
        aux2 = aux;
        aux = aux->getNext();
        delete aux2;
    }
    delete aux;

    first = NULL;
    last = NULL;
    tamanho = 0;
}


