#include <iostream>
#include <string>
#include <fstream>
#include "ColaEstatica/ColaEstatica.h"
#include "ListaSimple/PilaDinamica.h"
#include "Nodos/NodoBase.h"
#include "Nodos/NodoNumero.h"
#include "Nodos/NodoOperador.h"
using namespace std;

/*
 *Tarea Corta 1
 * Elaborado por:
 *      Jose Mariano Soto Núñez, 2020142918
 *      Pablo Ramirez
 */

static const string DIRECTORIO = "C:/Expresiones/";

void CargarArchivo(ColaEstatica& ColaArchivos, string NombreArchivo)
{
    ifstream Archivo;
    ListaSimple* ListaArchivo = new ListaSimple();
    const string Directorio = DIRECTORIO+NombreArchivo;
    
    Archivo.open(Directorio);
    for (string Linea; getline(Archivo, Linea); ) 
    {
        //Jank
        bool EsOperador = Linea=="+" || Linea=="-" || Linea=="*" || Linea=="/" || Linea=="^" || Linea=="(" || Linea==")";
        
        if (EsOperador)
        {
            ListaArchivo->AgregarNodo(new NodoOperador(Linea));    
        }else
        {
            ListaArchivo->AgregarNodo(new NodoNumero(stof(Linea)));
        }
    }
    //ListaArchivo.Mostrar();
    ColaArchivos.Insertar(ListaArchivo);
}

void EvaluarPostOperacion(PilaDinamica* Pila)
{
    while (NodoBase* Nodo = Pila->Pop())
    {
        Nodo->Mostrar();
        float Num2 = static_cast<NodoNumero*>(Pila->Pop())->Valor;
        float Num1 = static_cast<NodoNumero*>(Pila->Pop())->Valor;

        float Resultado = static_cast<NodoOperador*>(Nodo)->Evaluar(Num1, Num2);

        Pila->AgregarNodo(new NodoNumero(Resultado));
    }
}

int main()
{
    //Cargar archivos
    ColaEstatica ColaArchivos;
    CargarArchivo(ColaArchivos, "Arch1.txt");
    CargarArchivo(ColaArchivos, "Arch2.txt");
    CargarArchivo(ColaArchivos, "Arch3.txt");
    CargarArchivo(ColaArchivos, "Arch4.txt");
    CargarArchivo(ColaArchivos, "Arch5.txt");
    ColaArchivos.Mostrar();

    PilaDinamica* Pila = new PilaDinamica();

    Pila->AgregarNodo(new NodoNumero(3));
    Pila->AgregarNodo(new NodoNumero(4));
    Pila->AgregarNodo(new NodoOperador("+"));

    EvaluarPostOperacion(Pila);
    return 0;
}
