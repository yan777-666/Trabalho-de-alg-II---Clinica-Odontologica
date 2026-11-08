#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "structs.h"

void carregarPacientes(Paciente pacientes[], int *quantidade, int capacidade);
void carregarDentistas(Dentista dentistas[], int *quantidade, int capacidade);
void carregarConsultas(Consulta consultas[], int *quantidade, int capacidade);

void salvarPacientes(Paciente pacientes[], int quantidade);
void salvarDentistas(Dentista dentistas[], int quantidade);
void salvarConsultas(Consulta consultas[], int quantidade);

#endif