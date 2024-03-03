#include <iostream>
#include <string>
#include <fstream>
#include "ColaEstatica/ColaEstatica.h"
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

int main()
{
    ColaEstatica ColaArchivos;
    CargarArchivo(ColaArchivos, "Arch1.txt");
    CargarArchivo(ColaArchivos, "Arch2.txt");
    CargarArchivo(ColaArchivos, "Arch3.txt");
    CargarArchivo(ColaArchivos, "Arch4.txt");
    CargarArchivo(ColaArchivos, "Arch5.txt");
    ColaArchivos.Mostrar();
    return 0;
}
