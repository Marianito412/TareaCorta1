#pragma once
#include "../ListaSimple/ListaSimple.h"

class ColaEstatica
{
    static const int TAMANO = 5;
    
    int Frente;
    int Fondo;
    ListaSimple* Cola[TAMANO];
public:
    ColaEstatica();

    bool EstaVacia(){return Fondo < Frente;}

    void Insertar(ListaSimple* Lista);

    void Eliminar();

    void Mostrar(){
    for (int i = Frente; i <= Fondo; i++) {
        Cola[i]->Mostrar();
    }
};
