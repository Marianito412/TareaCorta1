#pragma once
#include <iostream>

#include "NodoBase.h"
#include <string>

enum ETipoOperador
{
    Suma,
    Resta,
    Multiplicacion,
    Division,
    Potencia,
    ParentesisAbre,
    ParentesisCierra
};

class NodoOperador: public NodoBase
{
public:
    ETipoOperador Operador;
    NodoOperador(ETipoOperador Op)
    {
        Operador = Op;
        TipoNodo = ETipoNodo::Operacion;
    }

    NodoOperador(std::string Op)
    {
        Operador = TraducirString(Op);
        TipoNodo = ETipoNodo::Operacion;
    }

    ETipoOperador TraducirString(std::string operador);
    
    virtual float Evaluar(float Num1, float Num2);

    int GetPrioridad(bool EnPila);

    void Mostrar() override;
};
