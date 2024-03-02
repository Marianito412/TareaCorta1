/*
 *Tarea Corta 1
 * Elaborado por:
 *      Jose Mariano Soto Núñez, 2020142918
 *      Pablo Ramirez
 */
#include <iostream>
#include <map>

#include "Nodos/NodoBase.h"
#include "Nodos/NodoNumero.h"
#include "Nodos/NodoOperador.h"

void CargarArchivos(FILE* Archivo)
{
    //D:/TEC/2024 SEMESTRE 1/ESTRUCTURAS DE DATOS GR 1/TareasCortas/TareaCorta
    fopen_s(&Archivo, "D:/TEC/2024 SEMESTRE 1/ESTRUCTURAS DE DATOS GR 1/TareasCortas/TareaCorta1/archivo.txt", "r");

    if (NULL == Archivo) {
        printf("No se pudo abrir el archivo");
    }
    else {
        char agregado[2];
        while (fgets(agregado, 2, Archivo) != NULL) {
            std::cout << agregado;
        }
        std::cout << std::endl;
        fclose(Archivo);
    }
}

int main()
{

    FILE* Archivo = nullptr;
    CargarArchivos(Archivo);
    ETipoNodo T= ETipoNodo::Numero;
    
    NodoNumero* n1 = new NodoNumero(2.0);

    n1->Siguiente = new NodoNumero(3.0);

    n1->Siguiente->Siguiente = new NodoOperador(ETipoOperador::Suma);

    NodoBase* aux = n1;
    while (aux)
    {
        std::cout<<aux->TipoNodo<<std::endl;
        aux= aux->Siguiente;
    }
    
    return 0;
}
