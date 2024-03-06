#include "PilaDinamica.h"

#include <iostream>

void PilaDinamica::AgregarNodo(NodoBase* Nodo)
{
    if (!Primero)
    {
        Primero = Nodo;
        Tope = Primero;
        return;    
    }
    NodoBase* Aux = Primero;
    while (Aux->Siguiente)
    {
        Aux=Aux->Siguiente;
    }
    Aux->Siguiente = Nodo;
    Tope = Nodo;
}

NodoBase* PilaDinamica::Pop()
{
    if (!Tope)
    {
        //std::cout << "La pila ya está vacia";
        return nullptr;
    }
    if (!Primero->Siguiente)
    {
        NodoBase* Encontrado = Primero;
        Primero = nullptr;
        Tope = nullptr;
        return Encontrado;
    }
    NodoBase* Aux = Primero;
    while(Aux->Siguiente!=Tope)
    {
        Aux = Aux->Siguiente;
    }
    NodoBase* Encontrado = Tope;
    Tope = Aux;
    Aux->Siguiente = nullptr;
    return Encontrado;
}
