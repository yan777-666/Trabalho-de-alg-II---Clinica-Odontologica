#include <stdio.h>
#include <string.h>
#include "dentistas.h"

void limparBuffer(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

void removerQuebraLinha(char str[]) {
    int tamanho = strlen(str);

    if (tamanho > 0 && str[tamanho - 1] == '\n') {
        str[tamanho - 1] = '\0';
    }
}

int buscarDentistaCRO(Dentista dentistas[], int qtd, int cro) {
    int i;

    for (i = 0; i < qtd; i++) {
        if (dentistas[i].cro == cro) {
            return i;
        }
    }

    return -1;
}

int cadastrarDentista(Dentista dentistas[], int *qtd, int capacidade) {
    Dentista novo;
    int cro;

    if (*qtd >= capacidade) {
        printf("\nLimite de dentistas atingido!\n");
        return 0;
    }

    printf("\n--- Cadastrar Dentista ---\n");

    printf("Digite o CRO: ");

    if (scanf("%d", &cro) != 1) {
        printf("CRO invalido!\n");
        limparBuffer();
        return 0;
    }

    limparBuffer();

    if (buscarDentistaCRO(dentistas, *qtd, cro) != -1) {
        printf("Dentista com esse CRO ja cadastrado!\n");
        return 0;
    }

    novo.cro = cro;

    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    removerQuebraLinha(novo.nome);

    printf("Especialidade: ");
    fgets(novo.especialidade, sizeof(novo.especialidade), stdin);
    removerQuebraLinha(novo.especialidade);

    printf("Telefone: ");
    fgets(novo.telefone, sizeof(novo.telefone), stdin);
    removerQuebraLinha(novo.telefone);

    dentistas[*qtd] = novo;

    (*qtd)++;

    printf("\nDentista cadastrado com sucesso!\n");

    return 1;
}

void alterarDentista(Dentista dentistas[], int qtd) {
    int cro;
    int indice;

    if (qtd == 0) {
        printf("\nNenhum dentista cadastrado!\n");
        return;
    }

    printf("\n--- Alterar Dentista ---\n");
    printf("Digite o CRO do dentista: ");

    if (scanf("%d", &cro) != 1) {
        printf("Entrada invalida!\n");
        limparBuffer();
        return;
    }

    limparBuffer();

    indice = buscarDentistaCRO(dentistas, qtd, cro);

    if (indice == -1) {
        printf("\nDentista nao encontrado!\n");
        return;
    }

    printf("\nNovo nome: ");
    fgets(dentistas[indice].nome, sizeof(dentistas[indice].nome), stdin);
    removerQuebraLinha(dentistas[indice].nome);

    printf("Nova especialidade: ");
    fgets(dentistas[indice].especialidade, sizeof(dentistas[indice].especialidade), stdin);
    removerQuebraLinha(dentistas[indice].especialidade);

    printf("Novo telefone: ");
    fgets(dentistas[indice].telefone, sizeof(dentistas[indice].telefone), stdin);
    removerQuebraLinha(dentistas[indice].telefone);

    printf("\nDentista atualizado com sucesso!\n");
}

void removerDentista(Dentista dentistas[], int *qtd, Consulta consultas[], int qtdConsultas) {
    int cro;
    int indice;
    int i;

    if (*qtd == 0) {
        printf("\nNenhum dentista cadastrado!\n");
        return;
    }

    printf("\n--- Remover Dentista ---\n");
    printf("Digite o CRO do dentista: ");

    if (scanf("%d", &cro) != 1) {
        printf("Entrada invalida!\n");
        limparBuffer();
        return;
    }

    limparBuffer();

    indice = buscarDentistaCRO(dentistas, *qtd, cro);

    if (indice == -1) {
        printf("\nDentista nao encontrado!\n");
        return;
    }

    for (i = 0; i < qtdConsultas; i++) {
        if (consultas[i].croDentista == cro) {
            printf("\nDentista possui consulta vinculada e nao pode ser removido!\n");
            return;
        }
    }

    for (i = indice; i < *qtd - 1; i++) {
        dentistas[i] = dentistas[i + 1];
    }

    (*qtd)--;

    printf("\nDentista removido com sucesso!\n");
}

void listarDentistas(Dentista dentistas[], int qtd) {
    int i;

    if (qtd == 0) {
        printf("\nNenhum dentista cadastrado!\n");
        return;
    }

    printf("\n--- LISTA DE DENTISTAS ---\n");

    for (i = 0; i < qtd; i++) {
        printf("\nDentista %d\n", i + 1);
        printf("CRO: %d\n", dentistas[i].cro);
        printf("Nome: %s\n", dentistas[i].nome);
        printf("Especialidade: %s\n", dentistas[i].especialidade);
        printf("Telefone: %s\n", dentistas[i].telefone);
    }
}