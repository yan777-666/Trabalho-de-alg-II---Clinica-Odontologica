#ifndef PACIENTES_H
#define PACIENTES_H

typedef struct {
    char cpf[15];
    char nome[100];
    char dataNascimento[11];
    char telefone[20];
} Paciente;

void listarPacientes(Paciente pacientes[], int quantidade);

#endif