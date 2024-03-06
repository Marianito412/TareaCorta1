#include "NodoOperador.h"
#include <stdexcept>
#include <cmath> 
ETipoOperador NodoOperador::TraducirString(std::string operador)
{
    if (operador=="+") return ETipoOperador::Suma;
    if (operador=="-") return ETipoOperador::Resta;
    if (operador=="*") return ETipoOperador::Multiplicacion;
    if (operador=="/") return ETipoOperador::Division;
    if (operador=="^") return ETipoOperador::Potencia;
    if (operador=="(") return ETipoOperador::ParentesisAbre;
    if (operador==")") return ETipoOperador::ParentesisCierra;
    throw std::invalid_argument("TraducirString no reconoce caracter" + operador);
}

float NodoOperador::Evaluar(float Num1, float Num2)
{
    switch (Operador)
    {
    case ETipoOperador::Suma:
        return Num1 + Num2;
    case ETipoOperador::Resta:
        return Num1 - Num2;
    case ETipoOperador::Multiplicacion:
        return Num1 * Num2;
    case ETipoOperador::Division:
        return Num1 / Num2;
    case ETipoOperador::Potencia:
        return std::pow(Num1, Num2);
    }
}

void NodoOperador::Mostrar()
{
    switch (Operador)
    {
    case ETipoOperador::Suma:
        std::cout<<"+";
        break;
    case ETipoOperador::Resta:
        std::cout<<"-";
        break;
    case ETipoOperador::Multiplicacion:
        std::cout<<"*";
        break;
    case ETipoOperador::Division:
        std::cout<<"/";
        break;
    case ETipoOperador::Potencia:
        std::cout<<"^";
        break;
    case ETipoOperador::ParentesisAbre:
        std::cout<<"(";
        break;
    case ETipoOperador::ParentesisCierra:
        std::cout<<")";
        break;
    default:
        throw std::invalid_argument("Tipo invalido");
    }
}
