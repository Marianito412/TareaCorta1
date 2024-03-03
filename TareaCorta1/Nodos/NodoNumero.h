#pragma once
#include "NodoBase.h"

class NodoNumero: public NodoBase
{
public:
    float Valor = 0;
    
    NodoNumero(float valor)
    {
        Valor = valor;
        TipoNodo = ETipoNodo::Numero;
    }

    void Mostrar() override;
};
