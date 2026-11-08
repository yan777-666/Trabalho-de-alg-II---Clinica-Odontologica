#include <stdio.h>
#include "structs.h"
#include "pacientes.h"
#include "dentistas.h"
#include "consultas.h"
#include "arquivos.h"

#define CAPACIDADE 5

int lerOpcao(void) {
    int opcao;

    if (scanf("%d", &opcao) != 1) {
        while (getchar() != '\n');
        return -1;
    }

    return opcao;
}

void menuPacientes(Paciente pacientes[], int *qtdPacientes) {
    int opcao;

    do {
        printf("\n========== MENU PACIENTES ==========\n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Listar pacientes\n");
        printf("3 - Atualizar paciente\n");
        printf("4 - Excluir paciente\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");

        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                cadastrarPaciente(pacientes, qtdPacientes, CAPACIDADE);
                break;

            case 2:
                listarPacientes(pacientes, *qtdPacientes);
                break;

            case 3:
                atualizarPaciente(pacientes, *qtdPacientes);
                break;

            case 4:
                excluirPaciente(pacientes, qtdPacientes);
                break;

            case 0:
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);
}

void menuDentistas(Dentista dentistas[], int *qtdDentistas,
                   Consulta consultas[], int qtdConsultas) {
    int opcao;

    do {
        printf("\n========== MENU DENTISTAS ==========\n");
        printf("1 - Cadastrar dentista\n");
        printf("2 - Listar dentistas\n");
        printf("3 - Atualizar dentista\n");
        printf("4 - Excluir dentista\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");

        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                cadastrarDentista(dentistas, qtdDentistas, CAPACIDADE);
                break;

            case 2:
                listarDentistas(dentistas, *qtdDentistas);
                break;

            case 3:
                alterarDentista(dentistas, *qtdDentistas);
                break;

            case 4:
                removerDentista(dentistas, qtdDentistas,
                                consultas, qtdConsultas);
                break;

            case 0:
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);
}

void menuConsultas(Consulta consultas[], int *qtdConsultas,
                   Paciente pacientes[], int qtdPacientes,
                   Dentista dentistas[], int qtdDentistas) {
    int opcao;

    do {
        printf("\n========== MENU CONSULTAS ==========\n");
        printf("1 - Cadastrar consulta\n");
        printf("2 - Listar consultas\n");
        printf("3 - Atualizar consulta\n");
        printf("4 - Excluir consulta\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");

        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                cadastrarConsulta(consultas, qtdConsultas, CAPACIDADE,
                                  pacientes, qtdPacientes,
                                  dentistas, qtdDentistas);
                break;

            case 2:
                listarConsultas(consultas, *qtdConsultas,
                                pacientes, qtdPacientes,
                                dentistas, qtdDentistas);
                break;

            case 3:
                atualizarConsulta(consultas, *qtdConsultas,
                                  pacientes, qtdPacientes,
                                  dentistas, qtdDentistas);
                break;

            case 4:
                excluirConsulta(consultas, qtdConsultas);
                break;

            case 0:
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);
}

int main(void) {
    Paciente pacientes[CAPACIDADE];
    Dentista dentistas[CAPACIDADE];
    Consulta consultas[CAPACIDADE];

    int qtdPacientes = 0;
    int qtdDentistas = 0;
    int qtdConsultas = 0;

    int opcao;

    carregarPacientes(pacientes, &qtdPacientes, CAPACIDADE);
    carregarDentistas(dentistas, &qtdDentistas, CAPACIDADE);
    carregarConsultas(consultas, &qtdConsultas, CAPACIDADE);

    printf("\n====================================\n");
    printf("   SISTEMA DE GERENCIAMENTO ODONTOLOGICO\n");
    printf("====================================\n");

    do {
        printf("\n============== MENU PRINCIPAL ==============\n");
        printf("1 - Gerenciar pacientes\n");
        printf("2 - Gerenciar dentistas\n");
        printf("3 - Gerenciar consultas\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                menuPacientes(pacientes, &qtdPacientes);
                break;

            case 2:
                menuDentistas(dentistas, &qtdDentistas,
                              consultas, qtdConsultas);
                break;

            case 3:
                menuConsultas(consultas, &qtdConsultas,
                              pacientes, qtdPacientes,
                              dentistas, qtdDentistas);
                break;

            case 0:
                salvarPacientes(pacientes, qtdPacientes);
                salvarDentistas(dentistas, qtdDentistas);
                salvarConsultas(consultas, qtdConsultas);

                printf("\nDados salvos com sucesso!\n");
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}