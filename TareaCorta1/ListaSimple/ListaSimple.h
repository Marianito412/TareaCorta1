#pragma once
#include "../Nodos/NodoBase.h"

class ListaSimple
{
protected:
    NodoBase* Primero = nullptr;
public:

    virtual void AgregarNodo(NodoBase* Nodo);

    void Mostrar();
};
