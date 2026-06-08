#include<iostream>
#include "historial.h"
#include "../estructuras.h"
#include <cstring>
#include <cstdlib>

/*
    MÓDULO: Historial

    Este archivo registra todas las acciones relevantes realizadas en el
    sistema mediante una estructura de pila. Permite almacenar eventos,
    consultar la última acción registrada, visualizar el historial completo
    y eliminar los registros existentes cuando sea necesario.
*/

using namespace std;
NodoHistorial* topHistorial = NULL;

void pushHistorial(const char* modulo, const char* accion){
    NodoHistorial* newAction = (NodoHistorial*) malloc(sizeof(NodoHistorial));
    if(newAction == NULL){
        cout<<"Error en memoria";
        return;
    }

    strcpy(newAction->registro.modulo, modulo);
    strcpy(newAction->registro.accion, accion);
    newAction->siguiente=topHistorial;
    topHistorial=newAction;
}

void peekHistorial(){
    if(topHistorial == NULL){
        cout<<"\nEl historial está vacío.";
        return;
    }
    cout<<"\n\n=================================";
    cout<<"\nHistorial";
    cout<<"\n=================================";
    cout<<"\n\nÚltima acción realizada:";
    cout << "\n----------------------------------------------------------------------------------";
    cout<<"\n"<< topHistorial->registro.modulo << ": " << topHistorial->registro.accion;
    cout << "\n----------------------------------------------------------------------------------";
}

void showHistorialRecursivo(NodoHistorial* nodo){
    if(nodo == NULL){
        return;
    }

    cout << "\n----------------------------------------------------------------------------------";
    cout << "\n" << nodo->registro.modulo
         << ": "
         << nodo->registro.accion;
    cout << "\n----------------------------------------------------------------------------------";

    showHistorialRecursivo(nodo->siguiente);
}

void showHistorial(){
    if(topHistorial == NULL){
        cout << "\nEl historial está vacío.";
        return;
    }

    cout<<"\n\n=================================";
    cout<<"\nHistorial";
    cout<<"\n=================================";
    cout<<"\n\nAcciones registradas:";

    showHistorialRecursivo(topHistorial);
}

void popHistorialRecursivo(NodoHistorial* nodo){
    if(nodo == NULL){
        return;
    }

    popHistorialRecursivo(nodo->siguiente);

    free(nodo);
}

void popHistorial(){
    if(topHistorial == NULL){
        cout << "\nEl historial está vacío.";
        return;
    }

    char confirmacion;

    cout << "\n\n=================================";
    cout << "\nEliminar historial";
    cout << "\n=================================";
    cout << "\n\n¿Está seguro de eliminar todo el historial? (S/N): ";
    cin >> confirmacion;

    if(confirmacion != 'S' && confirmacion != 's'){
        cout << "\nOperación cancelada.";
        return;
    }

    popHistorialRecursivo(topHistorial);

    topHistorial = NULL;

    cout << "\nHistorial eliminado correctamente.";
}