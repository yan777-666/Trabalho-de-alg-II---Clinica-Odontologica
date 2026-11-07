#include <stdio.h>
#include <string.h>
#include "pacientes.h"

int buscarPaciente(Paciente pacientes[], int quantidade, char cpf[]) {
    int i;

    for (i = 0; i < quantidade; i++) {
        if (strcmp(pacientes[i].cpf, cpf) == 0) {
            return i;
        }
    }

    return -1;
}

void cadastrarPaciente(Paciente pacientes[], int *quantidade, int capacidade) {
    if (*quantidade >= capacidade) {
        printf("\nLimite de pacientes atingido!\n");
        return;
    }

    printf("\nDigite o CPF: ");
    scanf(" %14s", pacientes[*quantidade].cpf);

    if (buscarPaciente(pacientes, *quantidade, pacientes[*quantidade].cpf) != -1) {
        printf("\nCPF ja cadastrado!\n");
        return;
    }

    printf("Digite o nome: ");
    scanf(" %99[^\n]", pacientes[*quantidade].nome);

    printf("Digite a data de nascimento: ");
    scanf(" %10[^\n]", pacientes[*quantidade].dataNascimento);

    printf("Digite o telefone: ");
    scanf(" %19[^\n]", pacientes[*quantidade].telefone);

    (*quantidade)++;

    printf("\nPaciente cadastrado com sucesso!\n");
}

void listarPacientes(Paciente pacientes[], int quantidade) {
    int i;

    if (quantidade == 0) {
        printf("\nNenhum paciente cadastrado!\n");
        return;
    }

    printf("\n--- LISTA DE PACIENTES ---\n");

    for (i = 0; i < quantidade; i++) {
        printf("\nPaciente %d\n", i + 1);
        printf("CPF: %s\n", pacientes[i].cpf);
        printf("Nome: %s\n", pacientes[i].nome);
        printf("Data de nascimento: %s\n", pacientes[i].dataNascimento);
        printf("Telefone: %s\n", pacientes[i].telefone);
    }
}

void atualizarPaciente(Paciente pacientes[], int quantidade) {
    char cpf[15];
    int indice;

    if (quantidade == 0) {
        printf("\nNenhum paciente cadastrado!\n");
        return;
    }

    printf("\nDigite o CPF do paciente: ");
    scanf(" %14s", cpf);

    indice = buscarPaciente(pacientes, quantidade, cpf);

    if (indice == -1) {
        printf("\nPaciente nao encontrado!\n");
        return;
    }

    printf("\nDigite o novo nome: ");
    scanf(" %99[^\n]", pacientes[indice].nome);

    printf("Digite a nova data de nascimento: ");
    scanf(" %10[^\n]", pacientes[indice].dataNascimento);

    printf("Digite o novo telefone: ");
    scanf(" %19[^\n]", pacientes[indice].telefone);

    printf("\nPaciente atualizado com sucesso!\n");
}

void excluirPaciente(Paciente pacientes[], int *quantidade) {
    char cpf[15];
    int indice;
    int i;

    if (*quantidade == 0) {
        printf("\nNenhum paciente cadastrado!\n");
        return;
    }

    printf("\nDigite o CPF do paciente: ");
    scanf(" %14s", cpf);

    indice = buscarPaciente(pacientes, *quantidade, cpf);

    if (indice == -1) {
        printf("\nPaciente nao encontrado!\n");
        return;
    }

    for (i = indice; i < *quantidade - 1; i++) {
        pacientes[i] = pacientes[i + 1];
    }

    (*quantidade)--;

    printf("\nPaciente excluido com sucesso!\n");
}