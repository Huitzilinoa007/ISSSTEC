#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

//PACIENTES
struct Paciente{
    int idPaciente;
    char nombre[40];
    char apellidos[40];
    int edad;
    char nss[11];
    int prioridad;
    int estadoRevision;
    char enfermedad[40];
    char fechaIngreso[10];
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
    char paciente[100];
};

struct NodoConsultorio
{
    Consultorio consultorio;
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
    char fecha[100];
    char accion[100];
};

struct NodoHistorial
{
    RegistroHistorial registro;
    NodoHistorial* siguiente;
};

#endif