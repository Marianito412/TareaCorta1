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
 *      Jose Mariano Soto NÃºÃ±ez, 2020142918
 *      Pablo Ramirez lopez 2019246933
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
    
    return;
}
int main()
{
    ColaEstatica ColaArchivos;
    CargarArchivo(ColaArchivos, "Arch1.txt");
    CargarArchivo(ColaArchivos, "Arch2.txt");
    CargarArchivo(ColaArchivos, "Arch3.txt");
    CargarArchivo(ColaArchivos, "Arch4.txt");
    CargarArchivo(ColaArchivos, "Arch5.txt");
    while (!ColaArchivos.EstaVacia()) {
        ListaSimple* ListaArchivo = ColaArchivos.Eliminar();
        ExpresionPosfija expresion;
        expresion.obtenerPrioridad(ListaArchivo);
        expresion.ConvertirAPosfijo(ListaArchivo);
        
        // Convertir a notación postfija
        std::cout << "Expresion postfija:" << std::endl;
        ConvertirAPosfijo(ListaArchivo);
        float resultado = expresion.evaluarPosfijo();
        std::cout << "Resultado: " << resultado << std::endl;
        
        delete ListaArchivo; // Liberar memoria
    }
    
class ExpresionPosfija {
private:
    std::stack<ETipoOperador> pilaOperadores; // Pila de operadores
    std::list<ETipoOperador> listaPostfija;    // Lista para la expresión postfija

public:
    ExpresionPosfija() {}
    void ConvertirAPosfijo(ListaSimple* listaInfija) {
        NodoBase* nodoActual = listaInfija->ObtenerPrimero();

        while (nodoActual != nullptr) {
            if (nodoActual->TipoNodo == ETipoNodo::Operacion) {
                NodoOperador* operador = dynamic_cast<NodoOperador*>(nodoActual);
                if (operador != nullptr) {
                    ETipoOperador tipoOperador = operador->Operador;
                    switch (tipoOperador) {
                        case ETipoOperador::Suma:
                        case ETipoOperador::Resta:
                        case ETipoOperador::Multiplicacion:
                        case ETipoOperador::Division:
                        case ETipoOperador::Potencia:
                            // Operador encontrado
                            while (!pilaOperadores.empty() && obtenerPrioridad(pilaOperadores.top(), true) >= obtenerPrioridad(tipoOperador, false)) {
                                listaPostfija.push_back(pilaOperadores.top());
                                pilaOperadores.pop();
                            }
                            pilaOperadores.push(tipoOperador);
                            break;
                        case ETipoOperador::ParentesisAbre:
                            // Paréntesis de apertura encontrado
                            pilaOperadores.push(tipoOperador);
                            break;
                        case ETipoOperador::ParentesisCierra:
                            // Paréntesis de cierre encontrado
                            while (!pilaOperadores.empty() && pilaOperadores.top() != ETipoOperador::ParentesisAbre) {
                                listaPostfija.push_back(pilaOperadores.top());
                                pilaOperadores.pop();
                            }
                            pilaOperadores.pop(); // Descartar paréntesis de apertura
                            break;
                        default:
                            break;
                    }
                }
            } else if (nodoActual->TipoNodo == ETipoNodo::Numero) {
                // Operando encontrado
                NodoNumero* numero = dynamic_cast<NodoNumero*>(nodoActual);
                if (numero != nullptr) {
                    listaPostfija.push_back(numero->Valor);
                }
            }

            nodoActual = nodoActual->Siguiente;
        }

        // Vaciar la pila de operadores al final
        while (!pilaOperadores.empty()) {
            listaPostfija.push_back(pilaOperadores.top());
            pilaOperadores.pop();
        }
    }
}
    // Método para evaluar una expresión postfija
    float evaluarPosfijo() {
        std::stack<float> pilaOperandos;

        for (ETipoOperador tipo : listaPostfija) {
            switch (tipo) {
                case ETipoOperador::Suma:
                    // Suma
                    {
                        float num2 = pilaOperandos.top();
                        pilaOperandos.pop();
                        float num1 = pilaOperandos.top();
                        pilaOperandos.pop();
                        pilaOperandos.push(num1 + num2);
                    }
                    break;
                case ETipoOperador::Resta:
                    // Resta
                    {
                        float num2 = pilaOperandos.top();
                        pilaOperandos.pop();
                        float num1 = pilaOperandos.top();
                        pilaOperandos.pop();
                        pilaOperandos.push(num1 - num2);
                    }
                    break;
                case ETipoOperador::Multiplicacion:
                    // Multiplicación
                    {
                        float num2 = pilaOperandos.top();
                        pilaOperandos.pop();
                        float num1 = pilaOperandos.top();
                        pilaOperandos.pop();
                        pilaOperandos.push(num1 * num2);
                    }
                    break;
                case ETipoOperador::Division:
                    // División
                    {
                        float num2 = pilaOperandos.top();
                        pilaOperandos.pop();
                        float num1 = pilaOperandos.top();
                        pilaOperandos.pop();
                        pilaOperandos.push(num1 / num2);
                    }
                    break;
                case ETipoOperador::Potencia:
                    // Potencia
                    {
                        float num2 = pilaOperandos.top();
                        pilaOperandos.pop();
                        float num1 = pilaOperandos.top();
                        pilaOperandos.pop();
                        pilaOperandos.push(pow(num1, num2));
                    }
                    break;
                default:
                    // Operando, se coloca en la pila de operandos
                    pilaOperandos.push(static_cast<float>(tipo));
                    break;
            }
        }
    int obtenerPrioridad(ETipoOperador operador, bool dentroPila) {
        switch (operador) {
            case ETipoOperador::Potencia: return dentroPila ? 3 : 4;
            case ETipoOperador::Multiplicacion:
            case ETipoOperador::Division: return 2;
            case ETipoOperador::Suma:
            case ETipoOperador::Resta: return 1;
            case ETipoOperador::ParentesisAbre: return dentroPila ? 0 : 5;
            default: return -1; // Operador no válido
        }
    }
        // El resultado final estará en la cima de la pila de operandos
        return pilaOperandos.top();
    }
    
    return 0;
}
