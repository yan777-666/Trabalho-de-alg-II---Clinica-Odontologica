#include <stdio.h>
#include "arquivos.h"


void carregarPacientes(Paciente pacientes[], int *quantidade, int capacidade) {
    FILE *arquivo;

    arquivo = fopen("pacientes.dat", "rb");

    *quantidade = 0;

    if (arquivo == NULL) {
        return;
    }

    while (*quantidade < capacidade &&
           fread(&pacientes[*quantidade], sizeof(Paciente), 1, arquivo) == 1) {
        (*quantidade)++;
    }

    fclose(arquivo);
}


void carregarDentistas(Dentista dentistas[], int *quantidade, int capacidade) {
    FILE *arquivo;

    arquivo = fopen("dentistas.dat", "rb");

    *quantidade = 0;

    if (arquivo == NULL) {
        return;
    }

    while (*quantidade < capacidade &&
           fread(&dentistas[*quantidade], sizeof(Dentista), 1, arquivo) == 1) {
        (*quantidade)++;
    }

    fclose(arquivo);
}
 

void carregarConsultas(Consulta consultas[], int *quantidade, int capacidade) {
    FILE *arquivo;

    arquivo = fopen("consultas.dat", "rb");

    *quantidade = 0;

    if (arquivo == NULL) {
        return;
    }

    while (*quantidade < capacidade &&
           fread(&consultas[*quantidade], sizeof(Consulta), 1, arquivo) == 1) {
        (*quantidade)++;
    }

    fclose(arquivo);
}


void salvarPacientes(Paciente pacientes[], int quantidade) {
    FILE *arquivo;

    arquivo = fopen("pacientes.dat", "wb");

    if (arquivo == NULL) {
        printf("Erro ao salvar pacientes!\n");
        return;
    }

    if (quantidade > 0) {
        fwrite(pacientes, sizeof(Paciente), quantidade, arquivo);
    }

    fclose(arquivo);
}


void salvarDentistas(Dentista dentistas[], int quantidade) {
    FILE *arquivo;

    arquivo = fopen("dentistas.dat", "wb");

    if (arquivo == NULL) {
        printf("Erro ao salvar dentistas!\n");
        return;
    }

    if (quantidade > 0) {
        fwrite(dentistas, sizeof(Dentista), quantidade, arquivo);
    }

    fclose(arquivo);
}

void salvarConsultas(Consulta consultas[], int quantidade) {
    FILE *arquivo;

    arquivo = fopen("consultas.dat", "wb");

    if (arquivo == NULL) {
        printf("Erro ao salvar consultas!\n");
        return;
    }

    if (quantidade > 0) {
        fwrite(consultas, sizeof(Consulta), quantidade, arquivo);
    }

    fclose(arquivo);
}