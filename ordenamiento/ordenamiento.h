#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

void orderByNombre(int orden);
void orderByEdad(int orden);
void orderByPrioridad(int orden);
void orderByEstadoRevision(int orden);

NodoPaciente* mergeSortNombre(NodoPaciente* head, int orden);
NodoPaciente* mergeNombre( NodoPaciente* izquierda, NodoPaciente* derecha, int orden);
NodoPaciente* mergeSortEdad(NodoPaciente* head, int orden);
NodoPaciente* mergeEdad(NodoPaciente* izquierda, NodoPaciente* derecha, int orden);
NodoPaciente* mergeSortPrioridad(NodoPaciente* head, int orden);
NodoPaciente* mergePrioridad(NodoPaciente* izquierda, NodoPaciente* derecha, int orden);
NodoPaciente* mergeSortEstadoRevision(NodoPaciente* head, int orden);
NodoPaciente* mergeEstadoRevision(NodoPaciente* izquierda, NodoPaciente* derecha, int orden);

NodoPaciente* dividirLista(NodoPaciente* head);
void printPacientesOrdenados(NodoPaciente* head, int criterio);

#endif