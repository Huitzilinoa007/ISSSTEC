#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include "../estructuras.h"

void mostrarTotal();
void mostrarAtendidos();
void mostrarEnCola();
void mostrarResumen();

// Funciones recursivas
int calcularTotal(NodoPaciente* nodo);
int calcularPorEstado(NodoPaciente* nodo, int estado);
int obtenerEdadMin(NodoPaciente* nodo, int minActual);
int obtenerEdadMax(NodoPaciente* nodo, int maxActual);

#endif