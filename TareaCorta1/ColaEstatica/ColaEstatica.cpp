#include "ColaEstatica.h"

#include <iostream>
using namespace std;

ColaEstatica::ColaEstatica()
{
    Frente = 0;
    Fondo = -1;
    for (auto& i : Cola)
    {
        i = nullptr;        
    }
}

void ColaEstatica::Insertar(ListaSimple* Lista)
{
    if(Fondo <=TAMANO-1){
        Fondo++;
        Cola[Fondo]= Lista;
        //cout<<"ColaEstatica::Insertar Nuevo Fondo:"<<Fondo<<endl;
    }
    else{
        cout<<"La cola esta llena";  
    }
}

void ColaEstatica::Eliminar()
{
    if(!EstaVacia()){
        Frente++;
    }
    else{
        cout<<"La cola esta vacia";  
    }
}

ListaSimple* ColaEstatica::GetElemento(int Pos)
{
    return Cola[Pos];
}

void ColaEstatica::Mostrar()
{
    for (const auto cola : Cola)
    {
        cola->Mostrar();
    }
}


