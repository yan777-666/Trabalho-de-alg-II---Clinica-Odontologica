#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dentistas.h"


static void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


static void removerQuebraLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int buscarDentistaCRO(const Dentista *dentistas, int qtd, int cro) {
    if (dentistas == NULL || qtd <= 0) {
        return -1;
    }

    for (int i = 0; i < qtd; i++) {
        if (dentistas[i].cro == cro) {
            return i;
        }
    }
    return -1;
}

int cadastrarDentista(Dentista **dentistas, int *qtd, int *capacidade, int (*garantirCap)(Dentista**, int*, int)) {
    if (dentistas == NULL || qtd == NULL || capacidade == NULL) {
        return 0;
    }

    
    if (garantirCap != NULL) {
        if (!garantirCap(dentistas, qtd, *capacidade)) {
            printf("Erro ao alocar memoria para cadastrar dentista.\n");
            return 0;
        }
    }

    int cro;
    printf("\n--- Cadastrar Dentista ---\n");
    printf("Digite o CRO: ");
    if (scanf("%d", &cro) != 1) {
        printf("CRO invalido.\n");
        limparBuffer();
        return 0;
    }
    limparBuffer();

    if (buscarDentistaCRO(*dentistas, *qtd, cro) != -1) {
        printf("Erro: Dentista com o CRO %d ja cadastrado.\n", cro);
        return 0;
    }

    Dentista novo;
    novo.cro = cro;

    printf("Nome: ");
    if (fgets(novo.nome, sizeof(novo.nome), stdin) != NULL) {
        removerQuebraLinha(novo.nome);
    }

    printf("Especialidade: ");
    if (fgets(novo.especialidade, sizeof(novo.especialidade), stdin) != NULL) {
        removerQuebraLinha(novo.especialidade);
    }

    printf("Telefone: ");
    if (fgets(novo.telefone, sizeof(novo.telefone), stdin) != NULL) {
        removerQuebraLinha(novo.telefone);
    }

    (*dentistas)[*qtd] = novo;
    (*qtd)++;

    printf("Dentista cadastrado com sucesso!\n");
    return 1;
}

void alterarDentista(Dentista *dentistas, int qtd) {
    if (dentistas == NULL || qtd == 0) {
        printf("Nenhum dentista cadastrado.\n");
        return;
    }

    int cro;
    printf("\n--- Alterar Dentista ---\n");
    printf("Digite o CRO do dentista a ser alterado: ");
    if (scanf("%d", &cro) != 1) {
        printf("Entrada invalida.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    int idx = buscarDentistaCRO(dentistas, qtd, cro);
    if (idx == -1) {
        printf("Dentista com CRO %d nao encontrado.\n", cro);
        return;
    }

    printf("Dados atuais: Nome: %s | Especialidade: %s | Telefone: %s\n",
           dentistas[idx].nome, dentistas[idx].especialidade, dentistas[idx].telefone);

    printf("\nDigite os novos dados:\n");
    printf("Novo Nome: ");
    if (fgets(dentistas[idx].nome, sizeof(dentistas[idx].nome), stdin) != NULL) {
        removerQuebraLinha(dentistas[idx].nome);
    }

    printf("Nova Especialidade: ");
    if (fgets(dentistas[idx].especialidade, sizeof(dentistas[idx].especialidade), stdin) != NULL) {
        removerQuebraLinha(dentistas[idx].especialidade);
    }

    printf("Novo Telefone: ");
    if (fgets(dentistas[idx].telefone, sizeof(dentistas[idx].telefone), stdin) != NULL) {
        removerQuebraLinha(dentistas[idx].telefone);
    }

    printf("Cadastro do dentista atualizado com sucesso!\n");
}


void removerDentista(Dentista **dentistas, int *qtd, const Consulta *consultas, int qtdConsultas) {
    if (dentistas == NULL || *dentistas == NULL || qtd == NULL || *qtd == 0) {
        printf("Nenhum dentista cadastrado.\n");
        return;
    }

    int cro;
    printf("\n--- Remover Dentista ---\n");
    printf("Digite o CRO do dentista a remover: ");
    if (scanf("%d", &cro) != 1) {
        printf("Entrada invalida.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    int idx = buscarDentistaCRO(*dentistas, *qtd, cro);
    if (idx == -1) {
        printf("Dentista com CRO %d nao encontrado.\n", cro);
        return;
    }

    
    if (consultas != NULL && qtdConsultas > 0) {
        for (int i = 0; i < qtdConsultas; i++) {
            if (consultas[i].croDentista == cro) {
                printf("Erro: O dentista nao pode ser removido pois possui consulta vinculada (ID Consulta: %d).\n", 
                       consultas[i].idConsulta);
                return;
            }
        }
    }

    
    for (int i = idx; i < (*qtd) - 1; i++) {
        (*dentistas)[i] = (*dentistas)[i + 1];
    }
    (*qtd)--;

    printf("Dentista removido com sucesso!\n");
}


void listarDentistas(const Dentista *dentistas, int qtd) {
    printf("\n================ LISTA DE DENTISTAS ================\n");
    if (dentistas == NULL || qtd == 0) {
        printf("Nenhum dentista cadastrado.\n");
        printf("====================================================\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("[%d] CRO: %d | Nome: %s | Especialidade: %s | Tel: %s\n",
               i + 1, dentistas[i].cro, dentistas[i].nome, dentistas[i].especialidade, dentistas[i].telefone);
    }
    printf("====================================================\n");
}
