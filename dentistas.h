#ifndef DENTISTAS_H
#define DENTISTAS_H

#include "structs.h"

int cadastrarDentista(Dentista **dentistas, int *qtd, int *capacidade, int (*garantirCap)(Dentista**, int*, int));
int buscarDentistaCRO(const Dentista *dentistas, int qtd, int cro);
void alterarDentista(Dentista *dentistas, int qtd);
void removerDentista(Dentista **dentistas, int *qtd, const Consulta *consultas, int qtdConsultas);
void listarDentistas(const Dentista *dentistas, int qtd);

#endif
