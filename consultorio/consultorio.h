#ifndef CONSULTORIO_H
#define CONSULTORIO_H

#include<../estructuras.h>

void insertConsultorio();
void updateConsultorio();
void deleteConsultorio();
void findConsultorio();
void findAllConsultorios();

NodoConsultorio* getConsultorio(int num);
void printConsultorio(NodoConsultorio* consultorio);

#endif