#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

//PACIENTES
struct Paciente{
    char nombre[40];
    char apellidos[40];
    int edad;
    char nss[11];
    int prioridad;
    int estadoRevision;
    char enfermedad[40];
};
struct NodoPaciente{
    Paciente paciente;
    NodoPaciente * siguiente;
};


//CONSULTORIOS
struct Consultorio
{
    int numero;
    char medico[100];
    char especialidad[100];
};

struct NodoConsultorio
{
    Consultorio dato;
    NodoConsultorio* siguiente;
};

//Lista de Espera
struct NodoListaEspera
{
    char paciente[100];
    NodoListaEspera* siguiente;
};

// Historial (pila)
struct RegistroHistorial
{
    char modulo[30];
    char accion[150];
};

struct NodoHistorial
{
    RegistroHistorial registro;
    NodoHistorial* siguiente;
};

#endif