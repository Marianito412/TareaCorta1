#include "NodoOperador.h"

void NodoOperador::Mostrar()
{
    for (auto mapa_operador : MapaOperadores)
    {
        if (mapa_operador.second == Operador)
        {
            std::cout<<mapa_operador.first;
            return;
        }
    }
}
