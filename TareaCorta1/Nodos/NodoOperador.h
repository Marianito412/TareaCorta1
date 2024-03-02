#pragma once
#include "NodoBase.h"

enum ETipoOperador
{
    Suma,
    Resta,
    Multiplicacion,
    Division,
    Potencia
};

class NodoOperador: public NodoBase
{
    ETipoOperador Operador;
public:
    NodoOperador(ETipoOperador Op)
    {
        Operador = Op;
        TipoNodo = ETipoNodo::Operacion;
    }
    virtual float Evaluar(float Num1, float Num2){return Num1+Num2;}
};

class NodoSuma: public NodoOperador
{
public:
    float Evaluar(float Num1, float Num2) {return Num1+Num2;}
};
