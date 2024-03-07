#pragma once
#include "NodoBase.h"
#include <map>
#include <string>

enum class ETipoOperador {
    Suma, Resta, Multiplicacion, Division, Potencia,
    ParentesisAbre, ParentesisCierra
};

class NodoOperador: public NodoBase {
private:
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
    int PDP;
    int PFP;

public:
    NodoOperador(ETipoOperador Op);

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

    virtual float Evaluar(float Num1, float Num2);

    void Mostrar() override;
};
