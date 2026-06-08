#include "../estructuras.h"
#ifndef HISTORIAL_H
#define HISTORIAL_H



void pushHistorial(const char* modulo, const char* accion);
void peekHistorial();
void showHistorial();
void showHistorialRecursivo(NodoHistorial* nodo);
void popHistorialRecursivo(NodoHistorial* nodo);
void popHistorial();

#endif