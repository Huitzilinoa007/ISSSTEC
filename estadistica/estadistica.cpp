#include <iostream>
#include "estadistica.h"

/*
    MÓDULO: Estadísticas

    Este archivo genera información estadística a partir de los pacientes
    registrados en el sistema. Mediante funciones recursivas calcula el
    total de pacientes, la cantidad de pacientes por estado de atención y
    obtiene valores relevantes como las edades mínima y máxima registradas,
    proporcionando un resumen general de la operación del sistema.
*/

using namespace std;

extern NodoPaciente* headPaciente;

int calcularTotal(NodoPaciente* nodo) {
    if (nodo == NULL) return 0; //caso base
    return 1 + calcularTotal(nodo->siguiente);
}

int calcularPorEstado(NodoPaciente* nodo, int estado) {
    if (nodo == NULL) return 0;
    int cond = (nodo->paciente.estadoRevision == estado) ? 1 : 0;
    return cond + calcularPorEstado(nodo->siguiente, estado);
}

int obtenerEdadMin(NodoPaciente* nodo, int minActual) {
    if (nodo == NULL) return minActual;
    if (nodo->paciente.edad < minActual) minActual = nodo->paciente.edad;
    return obtenerEdadMin(nodo->siguiente, minActual);
}

int obtenerEdadMax(NodoPaciente* nodo, int maxActual) {
    if (nodo == NULL) return maxActual;
    if (nodo->paciente.edad > maxActual) maxActual = nodo->paciente.edad;
    return obtenerEdadMax(nodo->siguiente, maxActual);
}

void mostrarTotal() {
    int total = calcularTotal(headPaciente);
    cout << "\n>>> Total de pacientes registrados: " << total << " <<<\n";
}

void mostrarAtendidos() {
    int atendidos = calcularPorEstado(headPaciente, 3);
    cout << "\n>>> Cantidad de pacientes atendidos: " << atendidos << " <<<\n";
}

void mostrarEnCola() {
    int espera = calcularPorEstado(headPaciente, 1);
    cout << "\n>>> Cantidad de pacientes esperando turno: " << espera << " <<<\n";
}

void mostrarResumen() {
    int total = calcularTotal(headPaciente);
    if (total == 0) {
        cout << "\nNo existen registros\n";
        return;
    }
    
    cout << "\n========================================";
    cout << "\nRESUMEN GENERAL";
    cout << "\n========================================";
    cout << "\n Total de pacientes:            " << total;
    cout << "\n Pacientes atendidos:           " << calcularPorEstado(headPaciente, 3);
    cout << "\n Pacientes esperando turno:     " << calcularPorEstado(headPaciente, 1);
    cout << "\n Pacientes en consulta:         " << calcularPorEstado(headPaciente, 2);
    cout << "\n Edad del paciente más joven:   " << obtenerEdadMin(headPaciente, headPaciente->paciente.edad) << " años";
    cout << "\n Edad del paciente más grande:  " << obtenerEdadMax(headPaciente, headPaciente->paciente.edad) << " años";
    cout << "\n========================================\n";
}