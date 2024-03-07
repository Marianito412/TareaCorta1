#pragma once

#include <iostream>
#include <map>
#include <string>
enum class ETipoNodo {Numero, Operacion };

class NodoBase
{
public:
    virtual ~NodoBase() = default;
    ETipoNodo TipoNodo = ETipoNodo::Numero;
    NodoBase* Siguiente = nullptr;
    float PDP;
    float PFP;

    virtual void Mostrar()=0 ;
};

enum class ETipoOperador {
    Suma, Resta, Multiplicacion, Division, Potencia,
    ParentesisAbre, ParentesisCierra
};
