#ifndef CONSULTORIO_H
#define CONSULTORIO_H

#include "../estructuras.h"

void createConsultorios();
void insertConsultorio();
void updateConsultorio();
void findConsultorio();
void findAllConsultorios();

NodoConsultorio* getConsultorio(int num);
void printConsultorio(NodoConsultorio* consultorio);

#endif