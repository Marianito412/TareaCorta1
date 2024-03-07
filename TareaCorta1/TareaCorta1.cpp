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

//Carga un archivo a lista simple y la agrega a una cola estatica
void CargarArchivo(ColaEstatica& ColaArchivos, string NombreArchivo)
{
    ifstream Archivo;
    ListaSimple* ListaArchivo = new ListaSimple();
    const string Directorio = DIRECTORIO+NombreArchivo;
    
    Archivo.open(Directorio);
    for (string Linea; getline(Archivo, Linea); ) 
    {
        //Dios perdonalos, porque no saben lo que hacen
        bool EsOperador = Linea=="+" || Linea=="-" || Linea=="*" || Linea=="/" || Linea=="^" || Linea=="(" || Linea==")";
        
        if (EsOperador)
        {
            ListaArchivo->AgregarNodo(new NodoOperador(Linea));    
        }else
        {
            ListaArchivo->AgregarNodo(new NodoNumero(stof(Linea)));
        }
    }
    ColaArchivos.Insertar(ListaArchivo);
}

//Convierte la expresion de infijo a postfijo
ListaSimple* ConvertirPostfijo(ListaSimple* ListaInfijo)
{
    NodoBase* Aux = ListaInfijo->Primero;
    PilaDinamica* PilaOps = new PilaDinamica();
    ListaSimple* ListaPostfijo = new ListaSimple();
    
    while (Aux)
    {
        //PilaOps->Mostrar();
        if (Aux->TipoNodo == ETipoNodo::Numero)
        {
            ListaPostfijo->AgregarNodo(new NodoNumero(dynamic_cast<NodoNumero*>(Aux)->Valor));
            Aux = Aux->Siguiente;
            continue;
        }
        if (NodoOperador* Operador = dynamic_cast<NodoOperador*>(Aux))
        {
            if (PilaOps->ListaVacia())
            {
                PilaOps->AgregarNodo(new NodoOperador(Operador->Operador));
                Aux = Aux->Siguiente;
                continue;
            }
            if (Operador->Operador == ETipoOperador::ParentesisCierra)
            {
                while (NodoOperador* OperadorFlush = dynamic_cast<NodoOperador*>(PilaOps->Pop()) )
                {
                    if (OperadorFlush->Operador == ETipoOperador::ParentesisAbre)
                    {
                        break;
                    }
                    ListaPostfijo->AgregarNodo(new NodoOperador(OperadorFlush->Operador));
                }
                Aux = Aux->Siguiente;
                continue;
            }
            NodoOperador* OpEnPila = dynamic_cast<NodoOperador*>(PilaOps->Tope);
            if (Operador->GetPrioridad(false)<=OpEnPila->GetPrioridad(true))
            {
                ListaPostfijo->AgregarNodo(new NodoOperador(OpEnPila->Operador));
                PilaOps->Pop();
                PilaOps->AgregarNodo(new NodoOperador(Operador->Operador));
                Aux = Aux->Siguiente;
                continue;
            }
            PilaOps->AgregarNodo(new NodoOperador(Operador->Operador));
            Aux = Aux->Siguiente;
        }
    }

    while (NodoOperador* OperadorFlush = dynamic_cast<NodoOperador*>(PilaOps->Pop())){
        ListaPostfijo->AgregarNodo(new NodoOperador(OperadorFlush->Operador));
    }
    //PilaOps->Mostrar();
    return ListaPostfijo;
}

//Evalua la expresion en postfijo y retorna una pila que debería contener un unico elemento con el resultado final de la evaluación
PilaDinamica* EvaluarPostOperacion(ListaSimple* ExpPost)
{
    NodoBase* Aux = ExpPost->Primero;
    PilaDinamica* PilaNums = new PilaDinamica();
    while (Aux)
    {
        if (Aux->TipoNodo == ETipoNodo::Numero)
        {
            PilaNums->AgregarNodo(new NodoNumero(dynamic_cast<NodoNumero*>(Aux)->Valor));
        }
        else
        {
            float Num2 = dynamic_cast<NodoNumero*>(PilaNums->Pop())->Valor;
            float Num1 = dynamic_cast<NodoNumero*>(PilaNums->Pop())->Valor;

            const float Resultado = dynamic_cast<NodoOperador*>(Aux)->Evaluar(Num1, Num2);
            PilaNums->AgregarNodo(new NodoNumero(Resultado));
        }
        Aux = Aux->Siguiente;
    }
    return PilaNums;
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
    //ColaArchivos.Mostrar();

    for (int i = 0; i<5; i++)
    {
        ListaSimple* ExpInfijo = ColaArchivos.GetElemento(i);
        ExpInfijo->Mostrar();

        ListaSimple* ExpPostfijo = ConvertirPostfijo(ExpInfijo);
        ExpPostfijo->Mostrar();

        PilaDinamica* Resultado = EvaluarPostOperacion(ExpPostfijo);
        Resultado->Mostrar();

        cout<<"______________________________________________________________________________"<<endl;
        
    }
    return 0;
    ColaArchivos.GetElemento(0)->Mostrar();
    ListaSimple* ExpPost = ConvertirPostfijo(ColaArchivos.GetElemento(0));
    ExpPost->Mostrar();

    PilaDinamica* Resultado = EvaluarPostOperacion(ExpPost);
    Resultado->Mostrar();
    
    return 0;
    ListaSimple* ExpPostFijo = new ListaSimple();

    //3 5 * 2 4 * + 6 -
    ExpPostFijo->AgregarNodo(new NodoNumero(3));
    ExpPostFijo->AgregarNodo(new NodoNumero(5));
    ExpPostFijo->AgregarNodo(new NodoOperador("*"));
    ExpPostFijo->AgregarNodo(new NodoNumero(2));
    ExpPostFijo->AgregarNodo(new NodoNumero(4));
    ExpPostFijo->AgregarNodo(new NodoOperador("*"));
    ExpPostFijo->AgregarNodo(new NodoOperador("+"));
    ExpPostFijo->AgregarNodo(new NodoNumero(6));
    ExpPostFijo->AgregarNodo(new NodoOperador("-"));

    PilaDinamica* PilaResultado = EvaluarPostOperacion(ExpPostFijo);
    PilaResultado->Mostrar();
    return 0;
}
