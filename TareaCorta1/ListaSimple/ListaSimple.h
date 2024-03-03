#pragma once
#include "../Nodos/NodoBase.h"

class ListaSimple
{
    NodoBase* Primero = nullptr;
public:

    void AgregarNodo(NodoBase* Nodo);

    void Mostrar();
};
