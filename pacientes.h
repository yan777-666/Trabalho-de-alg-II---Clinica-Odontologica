#ifndef PACIENTES_H
#define PACIENTES_H

#include "structs.h"

int buscarPaciente(Paciente pacientes[], int quantidade, char cpf[]);

void cadastrarPaciente(Paciente pacientes[], int *quantidade, int capacidade);

void listarPacientes(Paciente pacientes[], int quantidade);

void atualizarPaciente(Paciente pacientes[], int quantidade);

void excluirPaciente(Paciente pacientes[], int *quantidade);

#endif