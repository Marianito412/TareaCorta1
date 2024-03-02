#pragma once

enum ETipoNodo: int
{
    Numero,
    Operacion
};

class NodoBase
{
public:
    virtual ~NodoBase() = default;
    ETipoNodo TipoNodo = ETipoNodo::Numero;
    NodoBase* Siguiente = nullptr;
};
