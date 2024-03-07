#pragma once
#include "../Nodos/NodoBase.h"

class ListaSimple
{
private:
    NodoBase* Primero = nullptr;
#include "../Nodos/NodoBase.h"

class ListaSimple
{
private:
    NodoBase* Primero = nullptr;

public:
    // Método para agregar un nodo al final de la lista
    void AgregarNodo(NodoBase* Nodo)
    {
        if (Primero == nullptr) {
            Primero = Nodo;
        } else {
            NodoBase* ultimo = Primero;
            while (ultimo->Siguiente != nullptr) {
                ultimo = ultimo->Siguiente;
            }
            ultimo->Siguiente = Nodo;
        }
    }

    // Método para mostrar los nodos de la lista
    void Mostrar()
    {
        NodoBase* actual = Primero;
        while (actual != nullptr) {
            actual->Mostrar();
            actual = actual->Siguiente;
        }
    }
};
