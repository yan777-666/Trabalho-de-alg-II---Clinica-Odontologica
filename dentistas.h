#ifndef DENTISTAS_H
#define DENTISTAS_H

#include "structs.h"

int cadastrarDentista(Dentista dentistas[], int *qtd, int capacidade);
int buscarDentistaCRO(Dentista dentistas[], int qtd, int cro);
void alterarDentista(Dentista dentistas[], int qtd);
void removerDentista(Dentista dentistas[], int *qtd, Consulta consultas[], int qtdConsultas);
void listarDentistas(Dentista dentistas[], int qtd);

#endif