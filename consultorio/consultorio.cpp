#include <iostream>
#include "../estructuras.h"
#include "consultorio.h"
#include <cstring>
#include <cstdlib>

using namespace std;
NodoConsultorio* headConsultorio = NULL;

void insertConsultorio(){
    char medico[40];

    //Se pide el dato del médico asociado
    cout<<"\n\n=================================";
    cout<<"\nRegistar nuevo consultorio";
    cout<<"\n=================================";
    cin.ignore();
    cout<<"\nNombre del médico asignado: ";
    cin.getline(medico, 40);

    //Se crea el nuevo nodo a insertar a la lista de consultorios
    NodoConsultorio* newConsultorio = (NodoConsultorio*) malloc(sizeof(NodoConsultorio));
    if (newConsultorio == NULL) {
        cout << "\nError de memoria";
        return;
    }
    strcpy(newConsultorio->consultorio.medico, medico);
    strcpy(newConsultorio->consultorio.paciente, "Disponible");
    newConsultorio->siguiente = NULL;

    if (headConsultorio == NULL) {
        newConsultorio->consultorio.numero = 1;
        headConsultorio = newConsultorio;
    } else {
        NodoConsultorio* temp = headConsultorio;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }

        newConsultorio->consultorio.numero = temp->consultorio.numero + 1;
        temp->siguiente = newConsultorio;
    }

    cout<<"Consultorio registrado con éxito";

    //mostramos consultorios
    findAllConsultorios();
}

void updateConsultorio(){
    int numBuscar;
    cout << "\nIngrese el número de consultorio: ";
    cin >> numBuscar;

    NodoConsultorio* consultorio = getConsultorio(numBuscar);
    if (headConsultorio == NULL) {
        cout << "\nNo hay consultorios en el sistema.";
        return;
    }
    if(consultorio == NULL){
        cout<<"\nNo se encontró el consultorio #" << numBuscar;
    }else{
        char medicoNuevo[40];
        int opc;
        cout<<"\n¿Qué desea realizar?";
        cout<<"\n\n1.- Modificar médico asignado";
        cout<<"\n2.- Cancelar";
        cout<<"\n\nIngrese el número de la operación a realizar: ";
        cin>>opc;

        if (opc == 1){
            cout << "Médico asignado (actual): " << consultorio->consultorio.medico << "\n";
            cout << "Ingrese el nuevo nombre del médico: ";
            cin.getline(medicoNuevo, 40);
            //actualización
            strcpy(consultorio->consultorio.medico, medicoNuevo);
            cout << "Médico actualizado\n";
            printConsultorio(consultorio);
        }else if (opc == 2){
            cout << "No se realizaron cambios\n";
        }else{
            cout << "Opción no disponible\n";
        }
        
    }
}

void deleteConsultorio(){
    int idBorrar;
    cout << "\nIngrese el número de consultorio que desea eliminar: ";
    cin >> idBorrar;

    if (headConsultorio == NULL) {
        cout << "\nNo hay consultorios en el sistema.";
        return;
    }

    NodoConsultorio* temp = headConsultorio;
    NodoConsultorio* anterior = NULL;

    //borrar al inicio
    if (temp != NULL && temp->consultorio.numero == idBorrar) {
        headConsultorio = temp->siguiente;
        free(temp);
        cout << "\nConsultorio #" << idBorrar << " eliminado exitosamente.";
        return;
    }

    // borrar en medio
    while (temp != NULL && temp->consultorio.numero != idBorrar) {
        anterior = temp;
        temp = temp->siguiente;
    }
    if (temp == NULL) {
        cout << "\nNo se encontró el consultorio #" << idBorrar;
        return;
    }

    anterior->siguiente = temp->siguiente;
    free(temp);
    cout << "\nConsultorio #" << idBorrar << " eliminado exitosamente.";
}

void findConsultorio(){
    int idBuscar;
    cout << "\nIngrese el número de consultorio a buscar: ";
    cin >> idBuscar;

    NodoConsultorio* aux = getConsultorio(idBuscar);
    if (aux != NULL) {
        printConsultorio(aux);
    } else {
        cout << "\nConsultorio no encontrado.";
    }
}

void findAllConsultorios(){
    cout << "\n\n========================================";
    cout << "\nLISTADO DE CONSULTORIOS";
    cout << "\n========================================\n";

    if(headConsultorio == NULL){
        cout << "\nNo hay consultorios registrados.\n";
        return;
    }
    NodoConsultorio* temp = headConsultorio;

    while(temp != NULL){
        printConsultorio(temp);
        temp = temp->siguiente;
    }
    cout << "\n========================================\n";
}

NodoConsultorio* getConsultorio(int num){
    NodoConsultorio* aux = headConsultorio;
    while(aux->siguiente != NULL){
        if(aux->consultorio.numero == num){
            return aux;
        }
    }    
}

void printConsultorio(NodoConsultorio* consultorio){
    cout << "\n----------------------------------------";
    cout << "\nCONSULTORIO #" << consultorio->consultorio.numero;
    cout << "\n----------------------------------------";

    cout << "\nMédico asignado: "<< consultorio->consultorio.medico;
    cout << "\nPaciente actual: "<< consultorio->consultorio.paciente;
    cout << "\n";
}
