#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "structs.h"

int buscarConsulta(Consulta consultas[], int quantidade, int idConsulta);

void cadastrarConsulta(Consulta consultas[], int *quantidade, int capacidade,
                       Paciente pacientes[], int quantidadePacientes,
                       Dentista dentistas[], int quantidadeDentistas);

void listarConsultas(Consulta consultas[], int quantidade,
                     Paciente pacientes[], int quantidadePacientes,
                     Dentista dentistas[], int quantidadeDentistas);

void atualizarConsulta(Consulta consultas[], int quantidade,
                       Paciente pacientes[], int quantidadePacientes,
                       Dentista dentistas[], int quantidadeDentistas);

void excluirConsulta(Consulta consultas[], int *quantidade);

#endif