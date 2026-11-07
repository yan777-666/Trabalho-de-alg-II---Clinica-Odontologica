#ifndef PACIENTES_H
#define PACIENTES_H

typedef struct {
    char cpf[15];
    char nome[100];
    char dataNascimento[11];
    char telefone[20];
} Paciente;

int buscarPacientePorCPF(
    const Paciente pacientes[],
    int quantidade,
    const char cpf[]
);

void cadastrarPaciente(
    Paciente pacientes[],
    int *quantidade,
    int capacidade
);

void listarPacientes(
    const Paciente pacientes[],
    int quantidade
);

void atualizarPaciente(
    Paciente pacientes[],
    int quantidade
);

void excluirPaciente(
    Paciente pacientes[],
    int *quantidade
);

#endif