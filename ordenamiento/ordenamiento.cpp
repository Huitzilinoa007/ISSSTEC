#include <iostream>
#include "ordenamiento.h"
#include "../paciente/paciente.h"
#include <iomanip>
#include <cstring>

/*
    MÓDULO: Ordenamientos

    Este archivo implementa los procesos de ordenamiento de pacientes
    utilizando el algoritmo Merge Sort sobre listas enlazadas. Permite
    organizar los registros por nombre completo, edad, nivel de prioridad
    o estado de revisión, tanto en orden ascendente como descendente, para
    facilitar la consulta y análisis de la información.
*/

using namespace std;

void orderByNombre(int orden){
    cout<<"\n\n==================================================================";
    cout<<"\nPACIENTES ORDENADOS POR NOMBRE";
    cout<<"\n==================================================================\n";

    headPaciente = mergeSortNombre(headPaciente, orden);

    printPacientesOrdenados(headPaciente, 1);
}

void orderByEdad(int orden){
    cout<<"\n\n==================================================================";
    cout<<"\nPACIENTES ORDENADOS POR EDAD";
    cout<<"\n==================================================================\n";

    headPaciente = mergeSortEdad(headPaciente, orden);

    printPacientesOrdenados(headPaciente, 2);
}

void orderByPrioridad(int orden){
    cout<<"\n\n===========================================================================";
    cout<<"\nPACIENTES ORDENADOS POR NIVEL DE PRIORIDAD";
    cout<<"\n===========================================================================\n";

    headPaciente = mergeSortPrioridad(headPaciente, orden);

    printPacientesOrdenados(headPaciente, 3);
}

void orderByEstadoRevision(int orden){
    cout<<"\n\n==================================================================";
    cout<<"\nPACIENTES ORDENADOS POR ESTADO DE REVISIÓN";
    cout<<"\n==================================================================\n";

    headPaciente = mergeSortEstadoRevision(headPaciente, orden);

    printPacientesOrdenados(headPaciente, 4);
}

NodoPaciente* mergeSortNombre(NodoPaciente* head, int orden){
    if(head == NULL || head->siguiente == NULL){
        return head;
    }

    NodoPaciente* mitad = dividirLista(head);

    NodoPaciente* izquierda = mergeSortNombre(head, orden);
    NodoPaciente* derecha = mergeSortNombre(mitad, orden);

    return mergeNombre(izquierda, derecha, orden);
}

NodoPaciente* mergeNombre( NodoPaciente* izquierda, NodoPaciente* derecha, int orden){
    if(izquierda == NULL){
        return derecha;
    }

    if(derecha == NULL){
        return izquierda;
    }

    NodoPaciente* resultado = NULL;
    char nombreCompletoIzq[100], nombreCompletoDer[100];
    sprintf(nombreCompletoIzq, "%s %s", izquierda->paciente.nombre, izquierda->paciente.apellidos);
    sprintf(nombreCompletoDer, "%s %s", derecha->paciente.nombre, derecha->paciente.apellidos);
    
    if(orden == 1){
        if(strcmp(nombreCompletoIzq, nombreCompletoDer) <= 0){
            resultado = izquierda;
            resultado->siguiente = mergeNombre(izquierda->siguiente, derecha, orden);
        }else{
            resultado = derecha;
            resultado->siguiente = mergeNombre(izquierda, derecha->siguiente, orden);
        }
    }else{
        if(strcmp(nombreCompletoIzq, nombreCompletoDer) >= 0){
            resultado = izquierda;
            resultado->siguiente = mergeNombre(izquierda->siguiente, derecha, orden);
        }else{
            resultado = derecha;
            resultado->siguiente = mergeNombre(izquierda, derecha->siguiente, orden);
        }
    }
    return resultado;
}

NodoPaciente* mergeSortEdad(NodoPaciente* head, int orden){
    if(head == NULL || head->siguiente == NULL){
        return head;
    }

    NodoPaciente* mitad = dividirLista(head);

    NodoPaciente* izquierda = mergeSortEdad(head, orden);
    NodoPaciente* derecha = mergeSortEdad(mitad, orden);

    return mergeEdad(izquierda, derecha, orden);
}

NodoPaciente* mergeEdad(NodoPaciente* izquierda, NodoPaciente* derecha, int orden){
    if(izquierda == NULL){
        return derecha;
    }

    if(derecha == NULL){
        return izquierda;
    }

    NodoPaciente* resultado = NULL;
    if(orden == 1){
        if(izquierda->paciente.edad <= derecha->paciente.edad){
            resultado = izquierda;
            resultado->siguiente =
                mergeEdad(izquierda->siguiente, derecha,orden);
        }else{
            resultado = derecha;
            resultado->siguiente =
                mergeEdad(izquierda, derecha->siguiente, orden);
        }

    }else{
        if(izquierda->paciente.edad >= derecha->paciente.edad){
            resultado = izquierda;
            resultado->siguiente =
                mergeEdad(izquierda->siguiente, derecha, orden
                );
        }else{
            resultado = derecha;
            resultado->siguiente =
                mergeEdad(izquierda, derecha->siguiente,orden);
        }
    }

    return resultado;
}

NodoPaciente* mergeSortPrioridad(NodoPaciente* head, int orden){
    if(head == NULL || head->siguiente == NULL){
        return head;
    }

    NodoPaciente* mitad = dividirLista(head);

    NodoPaciente* izquierda = mergeSortPrioridad(head, orden);
    NodoPaciente* derecha = mergeSortPrioridad(mitad, orden);

    return mergePrioridad(izquierda, derecha, orden);
}

NodoPaciente* mergePrioridad(NodoPaciente* izquierda, NodoPaciente* derecha, int orden){
    if(izquierda == NULL){
        return derecha;
    }

    if(derecha == NULL){
        return izquierda;
    }

    NodoPaciente* resultado = NULL;
    if(orden == 1){
        if(izquierda->paciente.prioridad
            <= derecha->paciente.prioridad){
            resultado = izquierda;
            resultado->siguiente =
                mergePrioridad(
                    izquierda->siguiente,
                    derecha,
                    orden
                );
        }else{
            resultado = derecha;
            resultado->siguiente =
                mergePrioridad(
                    izquierda,
                    derecha->siguiente,
                    orden
                );
        }
    }else{

        if(izquierda->paciente.prioridad
            >= derecha->paciente.prioridad){
            resultado = izquierda;
            resultado->siguiente =
                mergePrioridad(
                    izquierda->siguiente,
                    derecha,
                    orden
                );
        }else{
            resultado = derecha;
            resultado->siguiente =
                mergePrioridad(
                    izquierda,
                    derecha->siguiente,
                    orden
                );
        }
    }

    return resultado;
}

NodoPaciente* mergeSortEstadoRevision(NodoPaciente* head, int orden){
    if(head == NULL || head->siguiente == NULL){
        return head;
    }

    NodoPaciente* mitad = dividirLista(head);

    NodoPaciente* izquierda = mergeSortEstadoRevision(head, orden);
    NodoPaciente* derecha = mergeSortEstadoRevision(mitad, orden);

    return mergeEstadoRevision(izquierda, derecha, orden);
}

NodoPaciente* mergeEstadoRevision(NodoPaciente* izquierda, NodoPaciente* derecha, int orden){
    if(izquierda == NULL){
        return derecha;
    }

    if(derecha == NULL){
        return izquierda;
    }

    NodoPaciente* resultado = NULL;

    if(orden == 1){

        if(izquierda->paciente.estadoRevision
            <= derecha->paciente.estadoRevision){

            resultado = izquierda;

            resultado->siguiente =
                mergeEstadoRevision(
                    izquierda->siguiente,
                    derecha,
                    orden
                );
        }else{

            resultado = derecha;

            resultado->siguiente =
                mergeEstadoRevision(
                    izquierda,
                    derecha->siguiente,
                    orden
                );
        }

    }else{

        if(izquierda->paciente.estadoRevision
            >= derecha->paciente.estadoRevision){

            resultado = izquierda;

            resultado->siguiente =
                mergeEstadoRevision(
                    izquierda->siguiente,
                    derecha,
                    orden
                );
        }else{

            resultado = derecha;

            resultado->siguiente =
                mergeEstadoRevision(
                    izquierda,
                    derecha->siguiente,
                    orden
                );
        }
    }

    return resultado;
}

NodoPaciente* dividirLista(NodoPaciente* head){
    if(head == NULL){
        return NULL;
    }

    NodoPaciente* lento = head;
    NodoPaciente* rapido = head->siguiente;

    while(rapido != NULL && rapido->siguiente != NULL){
        lento = lento->siguiente;
        rapido = rapido->siguiente->siguiente;
    }

    NodoPaciente* mitad = lento->siguiente;
    lento->siguiente = NULL;

    return mitad;
}

void printPacientesOrdenados(NodoPaciente* head, int criterio){
    if(head == NULL){
        cout << "\nNo hay pacientes registrados.";
        return;
    }
    int numero = 1;
    while(head != NULL){

        cout << "\n" << numero << ". Nombre: " << head->paciente.nombre << " " << head->paciente.apellidos;

        cout << "\n   NSS: " << head->paciente.nss;

        switch(criterio){

            case 1:
                break;

            case 2:
                cout << "\n   Edad: " << head->paciente.edad;
                break;

            case 3:
                cout << "\n   Prioridad: " << getNivelPrioridad(head->paciente.prioridad);
                break;

            case 4:
                cout << "\n   Estado: " << getEstadoRevision( head->paciente.estadoRevision);
                break;
        }

        cout << "\n------------------------------------------------------------------";

        numero++;
        head = head->siguiente;
    }
}