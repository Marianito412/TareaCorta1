#include "ListaSimple.h"

#include <iostream>

void ListaSimple::AgregarNodo(NodoBase* Nodo)
{
    if (!Primero)
    {
        Primero = Nodo;
        return;    
    }
    NodoBase* Aux = Primero;
    while (Aux->Siguiente)
    {
        Aux=Aux->Siguiente;
    }
    Aux->Siguiente = Nodo;
}

void ListaSimple::Mostrar()
{
    NodoBase* Aux = Primero;
    while (Aux)
    {
        Aux->Mostrar();
        std::cout << " -> ";
        Aux=Aux->Siguiente;
    }
    std::cout << "\n";
}
