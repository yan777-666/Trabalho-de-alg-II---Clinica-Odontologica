#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    char cpf[15];
    char nome[100];
    char dataNascimento[11];
    char telefone[20];
} Paciente;

typedef struct {
    int cro;
    char nome[100];
    char especialidade[100];
    char telefone[20];
} Dentista;

typedef struct {
    int idConsulta;
    char cpfPaciente[15];
    int croDentista;
    char dataConsulta[11];
    char horario[6];
} Consulta;

#endif