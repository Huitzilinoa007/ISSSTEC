#include <iostream>
#include "../estructuras.h"
#include "paciente.h"
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;
NodoPaciente* headPaciente = NULL;

void insertPaciente(){
    int edad, prioridad, estadoRevision = 0;
    char nombre[40], apellidos[40], nss[11], enfermedad[40], fechaIngreso[10];

    //Se piden los datos del paciente
    cout<<"\n\n=================================";
    cout<<"\nDar de alta paciente";
    cout<<"\n=================================";
    cout<<"\n\nIngrese los datos del paciente";

    cin.ignore();
    cout<<"\nNombre(s): ";
    cin.getline(nombre, 40);
    cout<<"Apellidos: ";
    cin.getline(apellidos, 40);
    cout<<"Edad: ";
    cin>>edad;
    cout<<"Número de Seguridad Social (NSS): ";
    cin>>nss;
    cout<<"Nivel de prioridad: ";
    cin>>prioridad;
    cout<<"Fecha de ingreso (DD/MM/YYYY): ";
    cin>>fechaIngreso;

    //Se crea el nuevo nodo a insertar a la lista de pacientes 
    NodoPaciente* newPaciente;
    newPaciente = (NodoPaciente*) malloc(sizeof(NodoPaciente));
    strcpy(newPaciente->paciente.nombre, nombre);
    strcpy(newPaciente->paciente.apellidos, apellidos);
    newPaciente->paciente.edad = edad;
    strcpy(newPaciente->paciente.nss, nss);
    newPaciente->paciente.prioridad = prioridad;
    newPaciente->paciente.estadoRevision = 0;
    strcpy(newPaciente->paciente.enfermedad, "Ninguna");
    strcpy(newPaciente->paciente.fechaIngreso, fechaIngreso);
    newPaciente->siguiente = NULL;

    //aquí se pone el nuevo paciente en la lista de pacientes
    if(headPaciente==NULL){
        newPaciente->paciente.idPaciente = 1;
        headPaciente = newPaciente;
    }else{
        int idPaciente = 1;
        NodoPaciente* temp = headPaciente;
        while(temp->siguiente != NULL){
            temp=temp->siguiente;
            idPaciente++;
        }
        newPaciente->paciente.idPaciente = idPaciente;
        temp->siguiente = newPaciente;
    }

    cout<<"Paciente registrado con éxito";

    //y ya que se registró al paciente, se muestran los pacientes registrados
    findAllPacientes();
}

void updatePaciente(){
    char nss[11];
    cout<<"\nIngrese el NSS del paciente: ";
    cin.getline(nss, 40);

    NodoPaciente* paciente = getPaciente(nss);
    if(paciente == headPaciente){
        cout<<"\nNo se encontró al paciente con NSS: ", nss, ". Intente con otro NSS.";
    }else{
        char nombre[40], apellidos[40], nss[11], enfermedad[40], fechaIngreso[10];
        int opc, edad, prioridad, estadoRevision;
        cout<<"\n¿Qué desea modificar?";
        cout<<"\n\n1.- Nombre(s): ";
        cout<<"\n2.- Apellidos";
        cout<<"\n3.- Edad";
        cout<<"\n4.- NSS";
        cout<<"\n5.- Enfermedad";
        cout<<"\n6.- Prioridd"; 
        cout<<"\n7.- Estado de Revisión";
        cout<<"\n8.- Fecha de ingreso";
        cout<<"\n9.- Cancelar";
        cout<<"\n\nIngrese el número de la operación que desea realizar: ";
        cin>>opc;

        switch (opc){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4: 
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            default:
                break;
        }
        printPaciente(paciente);
    }
}

void deletePaciente(){

}

void findPaciente(){

}

void findAllPacientes()
{
    cout << "\n\n========================================";
    cout << "\nLISTADO DE PACIENTES";
    cout << "\n========================================\n";

    if(headPaciente == NULL)
    {
        cout << "\nNo hay pacientes registrados.\n";
        return;
    }
    NodoPaciente* temp = headPaciente;

    while(temp != NULL)
    {
        printPaciente(temp);
        temp = temp->siguiente;
    }

    cout << "\n========================================\n";
}

NodoPaciente* getPaciente(char nssPaciente[11]){
    NodoPaciente* aux = headPaciente;
    while(aux->siguiente != NULL){
        if(aux->paciente.nss == nssPaciente){
            return aux;
        }
    }    
}

void printPaciente(NodoPaciente* paciente){
    cout << "\n----------------------------------------";
    cout << "\nPACIENTE #" << paciente->paciente.idPaciente;
    cout << "\n----------------------------------------";

    cout << "\nNombre(s): "<< paciente->paciente.nombre;

    cout << "\nApellidos: "<< paciente->paciente.apellidos;

    cout << "\nEdad: " << paciente->paciente.edad;

    cout << "\nNSS: " << paciente->paciente.nss;

    cout << "\nEnfermedad: " << paciente->paciente.enfermedad;

    cout << "\nPrioridad: " << getNivelPrioridad(paciente->paciente.prioridad);

    cout << "\nEstado: " << getEstadoRevision(paciente->paciente.estadoRevision);

    cout << "\nFecha de ingreso: " << paciente->paciente.fechaIngreso;

    cout << "\n";
}

const char* getNivelPrioridad(int prioridad)
{
    switch(prioridad)
    {
        case 0:
            return "CONSULTA GENERAL";

        case 1:
            return "MENOR DE EDAD";

        case 2:
            return "PERSONA CON DISCAPACIDAD";

        case 3:
            return "MAYOR DE EDAD";

        case 4:
            return "EMBARAZO";

        case 5:
            return "URGENCIA NO CRITICA";

        case 6:
            return "URGENCIA GRAVE";

        case 7:
            return "RIESGO VITAL";

        default:
            return "DESCONOCIDA";
    }
}

const char* getEstadoRevision(int estadoRevision)
{
    switch(estadoRevision)
    {
        case 0:
            return "SIN CITA";

        case 1:
            return "EN LISTA DE ESPERA";

        case 2:
            return "EN CONSULTA";

        case 3:
            return "ATENDIDO";

        case 4:
            return "CANCELADO";

        default:
            return "DESCONOCIDA";
    }
}