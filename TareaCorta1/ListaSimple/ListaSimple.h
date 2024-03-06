#pragma once
#include "../Nodos/NodoBase.h"

class ListaSimple
{
protected:
    
public:
    NodoBase* Primero = nullptr;
    bool ListaVacia(){return Primero==nullptr;}
    virtual void AgregarNodo(NodoBase* Nodo);

    void Mostrar();
};
