#pragma once
#include <iostream>

#include "NodoBase.h"
#include <map>
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
    std::map<std::string, ETipoOperador> MapaOperadores = {
        {"+", ETipoOperador::Suma},
        {"-", ETipoOperador::Resta},
        {"*", ETipoOperador::Multiplicacion},
        {"/", ETipoOperador::Division},
        {"^", ETipoOperador::Potencia},
        {"(", ETipoOperador::ParentesisAbre},
        {")", ETipoOperador::ParentesisCierra},
    };
    ETipoOperador Operador;
public:
    NodoOperador(ETipoOperador Op)
    {
        Operador = Op;
        TipoNodo = ETipoNodo::Operacion;
    }

    NodoOperador(std::string Op)
    {
        if (MapaOperadores.find(Op) == MapaOperadores.end())
        {
            std::cout << "NodoOperador: Operador invalido: "+Op <<std::endl;
            return;
        }
        Operador = MapaOperadores[Op];
        TipoNodo = ETipoNodo::Operacion;
    }
    virtual float Evaluar(float Num1, float Num2){return Num1+Num2;}

    void Mostrar() override;
};

class NodoSuma: public NodoOperador
{
public:
    float Evaluar(float Num1, float Num2) {return Num1+Num2;}
};
