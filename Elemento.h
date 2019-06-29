#pragma once

template<class TIPO>
class Elemento
{
private:
    Elemento<TIPO> *next;
    Elemento<TIPO> *prev;

    TIPO *data;

public:
    Elemento();
    ~Elemento();

    void setNext (Elemento<TIPO>* n);
    Elemento<TIPO>* getNext ();

    void setPrev (Elemento<TIPO>* p);
    Elemento<TIPO>* getPrev ();

    void setData (TIPO* d);
    TIPO* getData ();

    void delData();
};

template<class TIPO>
Elemento<TIPO>::Elemento()
{
    next = NULL;
    prev = NULL;
//    data = NULL;
}

template<class TIPO>
Elemento<TIPO>::~Elemento()
{
    next = NULL;
    prev = NULL;
//    data = NULL;
}

template<class TIPO>
void Elemento<TIPO>::setNext (Elemento<TIPO>* n)
{
    next = n;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getNext ()
{
    return next;
}

template<class TIPO>
void Elemento<TIPO>::setPrev (Elemento<TIPO>* p)
{
   prev = p;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getPrev ()
{
   return prev;
}

template<class TIPO>
void Elemento<TIPO>::setData (TIPO* d)
{
   data = d;
}

template<class TIPO>
TIPO* Elemento<TIPO>::getData()
{
   return data;
}

template<class TIPO>
void Elemento<TIPO>::delData()
{
   data->del();
}
