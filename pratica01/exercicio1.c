#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** nomes = NULL;
int totalNomes = 0;

void adicionarNome();
void excluirNome();
void listarNomes();

int main() {
    int opcao;

    while(1){
        printf("===== Biblioteca de Nomes =====\n");
        printf("1. Adicionar nome\n");
        printf("2. Excluir nome\n");
        printf("3. Listar nomes\n");
        printf("4. Sair\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        if (opcao == 1) {
            adicionarNome();
        } else if (opcao == 2) {
            excluirNome();
        } else if (opcao == 3) {
            listarNomes();
        } else if (opcao == 4) {
            printf("Saindo...\n");
            break;
        } else {
            printf("Opcao invalida!\n");
        }
        
    }

    for (int i = 0; i < totalNomes; i++) {
        free(nomes[i]);
    }
    free(nomes);
    
    return 0;
}
    
void adicionarNome() {
    totalNomes++;
    nomes = realloc(nomes, totalNomes * sizeof(char*));
    nomes[totalNomes - 1] = malloc(50 * sizeof(char));

    printf("Digite o nome: ");
    scanf("%s", nomes[totalNomes - 1]);
    printf("Nome adicionado!\n");
}

void excluirNome() {
    if (totalNomes == 0) {
        printf("Lista vazia!\n");
        return;
    }

    listarNomes();
    printf("Digite o numero do nome para excluir: ");
    int numero;
    scanf("%d", &numero);

    if (numero < 1 || numero > totalNomes) {
        printf("Numero invalido!\n");
        return;
    }

    free(nomes[numero - 1]);

    for (int i = numero - 1; i < totalNomes - 1; i++) {
        nomes[i] = nomes[i + 1];
    }

    totalNomes--;
    nomes = realloc(nomes, totalNomes * sizeof(char*));
    printf("Nome excluido!\n");
}

void listarNomes() {
    if (totalNomes == 0) {
        printf("Lista vazia!\n");
        return;
    }

    printf("Nomes na lista:\n");
    for (int i = 0; i < totalNomes; i++) {
        printf("%d. %s\n", i + 1, nomes[i]);
    }
}