#include<iostream>
#include "menu.h"
#include "../paciente/paciente.cpp"
#include "../historial/historial.cpp"
#include "../ordenamiento/ordenamiento.cpp"
#include "../consultorio/consultorio.cpp"
#include "../atencion/atencion.cpp"
#include "../estadistica/estadistica.cpp"

/*
    MÓDULO: Menús

    Este archivo contiene la interacción principal con el usuario. Administra
    la navegación entre los distintos módulos del sistema mediante menús y
    submenús, permitiendo acceder a las funcionalidades de pacientes,
    consultorios, atención médica, historial, estadísticas y ordenamientos.
*/

using namespace std;

void menuPrincipal(){
    bool verifi = true;
    do{
        cout<<"\n\n==========================================================";
        cout<<"\nISSSTEC";
        cout<<"\nInstituto de Servicios de Software y Sistemas Tecnológicos";
        cout<<"\n==============================================================";
        cout<<"\n\n1.- Pacientes";
        cout<<"\n2.- Consultorios";
        cout<<"\n3.- Atención médica";
        cout<<"\n4.- Ordenamientos";
        cout<<"\n5.- Estadísticas";
        cout<<"\n6.- Historial";
        cout<<"\n7.- Salir\n\nIngrese el número del menú al que desea ingresar: ";

        int opc = 0;
        cin>>opc;
        switch (opc){
        case 1:
            menuPacientes();
            break;    
        case 2:
            menuConsultorios();
            break;
        case 3:
            menuAtencionMedica();
            break;
        case 4:
            menuOrdenamientos();
            break;
        case 5:
            menuEstadisticas();
            break;
        case 6:
            menuHistorial();
            break;
        case 7: 
            cout<<"\n\n=================================";
            cout<<"\nFin del programa";
            cout<<"\n=================================\n";
            verifi = false;
            break;
        default:
            cout<<"ERROR: Ingrese un valor en el rango dado.";
            break;
        }
    }while(verifi);
}


//Los cout's sólo los puse para probar que funcione
//se los puedes quitar después, va?
void menuPacientes(){
    bool verifi;
    do{
        cout<<"\n\n=================================";
        cout<<"\nPacientes";
        cout<<"\n=================================";
        cout<<"\n\n1.- Registrar paciente";
        cout<<"\n2.- Modificar paciente";
        cout<<"\n3.- Eliminar paciente";
        cout<<"\n4.- Consultar paciente";
        cout<<"\n5.- Mostrar todos los pacientes";
        cout<<"\n6.- Regresar\n\nIngrese el número de la operación que desea realizar: ";
        cout<<"";

        int opc = 0;
        cin>>opc;

        switch (opc){
        case 1:
            insertPaciente();
            break;
        case 2:
            updatePaciente();
            break;
        case 3:
            deletePaciente();
            break;
        case 4:
            findPaciente();
            break;
        case 5:
            findAllPacientes();
            break;
        case 6:
            verifi = false;
            break;
        default:
            verifi = false;
            break;
        }

    }while(verifi);
}


void menuConsultorios(){
    bool verifi;
    createConsultorios();
    do{
        cout<<"\n\n=================================";
        cout<<"\nConsultorios";
        cout<<"\n=================================";
        cout<<"\n\n1.- Registrar consultorio";
        cout<<"\n2.- Modificar consultorio";
        cout<<"\n3.- Buscar consultorio";
        cout<<"\n4.- Mostrar todos los consultorios";
        cout<<"\n5.- Salir\n\nIngrese el número de la operación que desea realizar: ";
        cout<<"";

        int opc = 0;
        cin>>opc;

        switch (opc){
        case 1:
            insertConsultorio();
            break;
        case 2:
            updateConsultorio();
            break;
        case 3:
            findConsultorio();
            break;
        case 4:
            findAllConsultorios();
            break;
        case 5:
            verifi = false;
            break;
        default:
            verifi = false;
            break;
        }

    }while(verifi);
}
void menuAtencionMedica(){
    bool verifi;
    createConsultorios();
    do{
        cout<<"\n\n=================================";
        cout<<"\nAtención médica";
        cout<<"\n=================================";
        cout<<"\n\n1.- Agregar paciente a la lista de espera";
        cout<<"\n2.- Atender paciente";
        cout<<"\n3.- Finalizar consulta";
        cout<<"\n4.- Mostrar lista de espera";
        cout<<"\n5.- Salir\n\nIngrese el número de la operación que desea realizar: ";
        cout<<"";

        int opc = 0;
        cin>>opc;

        switch (opc){
        case 1:
            agregarACola();
            break;
        case 2:
            atenderPaciente();
            break;
        case 3:
            finalizarConsulta();
            break;
        case 4:
            mostrarColaEspera();
            break;
        case 5:
            verifi = false;
            break;
        default:
            verifi = false;
            break;
        }

    }while(verifi);
}
void menuOrdenamientos(){
    if(headPaciente == NULL || headPaciente->siguiente == NULL){
        cout<<"\nNo hay suficientes pacientes para ordenarlos.";
        return;
    }
    
    bool verifi = true;
    do{
        cout<<"\n\n=================================";
        cout<<"\nOrdenamientos";
        cout<<"\n=================================";
        cout<<"\n\nOrdenar pacientes por:";
        cout<<"\n1.- Nombre";
        cout<<"\n2.- Edad";
        cout<<"\n3.- Nivel de prioridad";
        cout<<"\n4.- Estado de revisión";
        cout<<"\n5.- Regresar\n\nIngrese el número de la operación que desea realizar: ";
        cout<<"";

        int opc = 0, orden = 0;
        cin>>opc;
        switch (opc){
            case 1:
                orden = pedirOrden();
                orderByNombre(orden);
                break;
            case 2:
                orden = pedirOrden();
                orderByEdad(orden);
                break;
            case 3:
                orden = pedirOrden();
                orderByPrioridad(orden);
                break;
            case 4:
                orden = pedirOrden();
                orderByEstadoRevision(orden);
                break;
            case 5:
                verifi = false;
                break;
            default:
                verifi = false;
                break;
        }
    }while(verifi);
}
int pedirOrden(){
    int opc = 0;
    cout<<"\nOrden: ";
    cout<<"\n1.-Ascendente";
    cout<<"\n2.-Descendente";
    cout<<"\nIngrese el número de la operación a realizar: ";
    cin>>opc;
    return opc;
}
void menuEstadisticas(){
    bool verifi;
    do{
        cout<<"\n\n=================================";
        cout<<"\nEstadísticas";
        cout<<"\n=================================";
        cout<<"\n\n1.- Total de pacientes registrados";
        cout<<"\n2.- Pacientes atendidos";
        cout<<"\n3.- Pacientes en espera";
        cout<<"\n4.- Resumen general";
        cout<<"\n5.- Salir\n\nIngrese el número de la operación que desea realizar: ";
        cout<<"";

        int opc = 0;
        cin>>opc;

        switch (opc){
        case 1:
            mostrarTotal();
            break;
        case 2:
            mostrarAtendidos();
            break;
        case 3:
            mostrarEnCola();
            break;
        case 4:
            mostrarResumen();
            break;
        case 5:
            verifi = false;
            break;
        default:
            verifi = false;
            break;
        }

    }while(verifi);
}
void menuHistorial(){
    bool verifi = true;
    do{
        cout<<"\n\n=================================";
        cout<<"\nHistorial";
        cout<<"\n=================================";
        cout<<"\n\n1.- Ver última acción";
        cout<<"\n2.- Ver todo el historial";
        cout<<"\n3.- Eliminar historial";
        cout<<"\n4.- Regresar\n\nIngrese el número de la operación que desea realizar: ";
        cout<<"";

        int opc = 0;
        cin>>opc;

        switch (opc){
            case 1:
                peekHistorial();
                break;
            case 2:
                showHistorial();
                break;
            case 3:
                popHistorial();
                break;
            case 4:
                verifi = false;
                break;
            default:
                verifi = false;
                break;
        }
    }while(verifi);
}
