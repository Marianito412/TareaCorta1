#pragma once
#include <vcruntime.h>

#include "ListaSimple.h"

class PilaDinamica : public ListaSimple
{
    NodoBase* Tope = nullptr;
public:
    void AgregarNodo(NodoBase* Nodo) override;

    NodoBase* Pop();
};
