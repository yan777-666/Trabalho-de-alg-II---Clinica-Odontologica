#include <stdio.h>
#include <string.h>
#include "consultas.h"

int buscarConsulta(Consulta consultas[], int quantidade, int idConsulta) {
    int i;

    for (i = 0; i < quantidade; i++) {
        if (consultas[i].idConsulta == idConsulta) {
            return i;
        }
    }

    return -1;
}

static int buscarPacientePorCPF(Paciente pacientes[], int quantidade, char cpf[]) {
    int i;

    for (i = 0; i < quantidade; i++) {
        if (strcmp(pacientes[i].cpf, cpf) == 0) {
            return i;
        }
    }

    return -1;
}

static int buscarDentistaPorCRO(Dentista dentistas[], int quantidade, int cro) {
    int i;

    for (i = 0; i < quantidade; i++) {
        if (dentistas[i].cro == cro) {
            return i;
        }
    }

    return -1;
}

void cadastrarConsulta(Consulta consultas[], int *quantidade, int capacidade,
                       Paciente pacientes[], int quantidadePacientes,
                       Dentista dentistas[], int quantidadeDentistas) {
    Consulta nova;

    if (*quantidade >= capacidade) {
        printf("\nLimite de consultas atingido!\n");
        return;
    }

    if (quantidadePacientes == 0 || quantidadeDentistas == 0) {
        printf("\nCadastre pelo menos um paciente e um dentista primeiro!\n");
        return;
    }

    printf("\n--- CADASTRAR CONSULTA ---\n");

    printf("Digite o ID da consulta: ");
    if (scanf("%d", &nova.idConsulta) != 1) {
        printf("\nID invalido!\n");
        return;
    }

    if (buscarConsulta(consultas, *quantidade, nova.idConsulta) != -1) {
        printf("\nEsse ID ja esta cadastrado!\n");
        return;
    }

    printf("Digite o CPF do paciente: ");
    scanf(" %14s", nova.cpfPaciente);

    if (buscarPacientePorCPF(pacientes, quantidadePacientes,
                             nova.cpfPaciente) == -1) {
        printf("\nPaciente nao encontrado!\n");
        return;
    }

    printf("Digite o CRO do dentista: ");
    if (scanf("%d", &nova.croDentista) != 1) {
        printf("\nCRO invalido!\n");
        return;
    }

    if (buscarDentistaPorCRO(dentistas, quantidadeDentistas,
                             nova.croDentista) == -1) {
        printf("\nDentista nao encontrado!\n");
        return;
    }

    printf("Digite a data da consulta (DD/MM/AAAA): ");
    scanf(" %10s", nova.dataConsulta);

    printf("Digite o horario (HH:MM): ");
    scanf(" %5s", nova.horario);

    consultas[*quantidade] = nova;
    (*quantidade)++;

    printf("\nConsulta cadastrada com sucesso!\n");
}

void listarConsultas(Consulta consultas[], int quantidade,
                     Paciente pacientes[], int quantidadePacientes,
                     Dentista dentistas[], int quantidadeDentistas) {
    int i;
    int indicePaciente;
    int indiceDentista;

    if (quantidade == 0) {
        printf("\nNenhuma consulta cadastrada!\n");
        return;
    }

    printf("\n--- LISTA DE CONSULTAS ---\n");

    for (i = 0; i < quantidade; i++) {
        indicePaciente = buscarPacientePorCPF(
            pacientes, quantidadePacientes, consultas[i].cpfPaciente
        );

        indiceDentista = buscarDentistaPorCRO(
            dentistas, quantidadeDentistas, consultas[i].croDentista
        );

        printf("\nConsulta %d\n", i + 1);
        printf("ID: %d\n", consultas[i].idConsulta);
        printf("CPF do paciente: %s\n", consultas[i].cpfPaciente);

        if (indicePaciente != -1) {
            printf("Nome do paciente: %s\n", pacientes[indicePaciente].nome);
        }

        printf("CRO do dentista: %d\n", consultas[i].croDentista);

        if (indiceDentista != -1) {
            printf("Nome do dentista: %s\n", dentistas[indiceDentista].nome);
        }

        printf("Data: %s\n", consultas[i].dataConsulta);
        printf("Horario: %s\n", consultas[i].horario);
    }
}

void atualizarConsulta(Consulta consultas[], int quantidade,
                       Paciente pacientes[], int quantidadePacientes,
                       Dentista dentistas[], int quantidadeDentistas) {
    int id;
    int indice;
    int cro;
    char cpf[15];

    if (quantidade == 0) {
        printf("\nNenhuma consulta cadastrada!\n");
        return;
    }

    printf("\nDigite o ID da consulta que deseja alterar: ");
    if (scanf("%d", &id) != 1) {
        printf("\nID invalido!\n");
        return;
    }

    indice = buscarConsulta(consultas, quantidade, id);

    if (indice == -1) {
        printf("\nConsulta nao encontrada!\n");
        return;
    }

    printf("Digite o novo CPF do paciente: ");
    scanf(" %14s", cpf);

    if (buscarPacientePorCPF(pacientes, quantidadePacientes, cpf) == -1) {
        printf("\nPaciente nao encontrado!\n");
        return;
    }

    printf("Digite o novo CRO do dentista: ");
    if (scanf("%d", &cro) != 1) {
        printf("\nCRO invalido!\n");
        return;
    }

    if (buscarDentistaPorCRO(dentistas, quantidadeDentistas, cro) == -1) {
        printf("\nDentista nao encontrado!\n");
        return;
    }

    strcpy(consultas[indice].cpfPaciente, cpf);
    consultas[indice].croDentista = cro;

    printf("Digite a nova data (DD/MM/AAAA): ");
    scanf(" %10s", consultas[indice].dataConsulta);

    printf("Digite o novo horario (HH:MM): ");
    scanf(" %5s", consultas[indice].horario);

    printf("\nConsulta atualizada com sucesso!\n");
}

void excluirConsulta(Consulta consultas[], int *quantidade) {
    int id;
    int indice;
    int i;

    if (*quantidade == 0) {
        printf("\nNenhuma consulta cadastrada!\n");
        return;
    }

    printf("\nDigite o ID da consulta que deseja excluir: ");
    if (scanf("%d", &id) != 1) {
        printf("\nID invalido!\n");
        return;
    }

    indice = buscarConsulta(consultas, *quantidade, id);

    if (indice == -1) {
        printf("\nConsulta nao encontrada!\n");
        return;
    }

    for (i = indice; i < *quantidade - 1; i++) {
        consultas[i] = consultas[i + 1];
    }

    (*quantidade)--;

    printf("\nConsulta excluida com sucesso!\n");
}