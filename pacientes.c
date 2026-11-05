#include <stdio.h>
#include <string.h>
#include "pacientes.h"

void listarPacientes(Paciente pacientes[], int quantidade) {
    int i;

    if (quantidade == 0) {
        printf("Nenhum paciente cadastrado.\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        printf("\nPaciente %d\n", i + 1);
        printf("CPF: %s\n", pacientes[i].cpf);
        printf("Nome: %s\n", pacientes[i].nome);
        printf("Data de nascimento: %s\n", pacientes[i].dataNascimento);
        printf("Telefone: %s\n", pacientes[i].telefone);
    }
}