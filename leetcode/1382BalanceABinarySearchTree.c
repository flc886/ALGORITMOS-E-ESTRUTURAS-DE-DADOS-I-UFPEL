#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void salvarEmVetor(struct TreeNode* raiz, int* vetor, int* indice) {
    if(raiz == NULL) return;

    salvarEmVetor(raiz->left, vetor, indice);
    vetor[(*indice)++] = raiz->val;
    salvarEmVetor(raiz->right, vetor, indice);
}

struct TreeNode* criarNo(int valor) {
    struct TreeNode* no = malloc(sizeof(struct TreeNode));
    no->val = valor;
    no->left = NULL;
    no->right = NULL;
    return no;
}

struct TreeNode* montarArvore(int* vetor, int esq, int dir) {
    if(esq > dir) return NULL;

    int meio = esq + (dir - esq) / 2;
    struct TreeNode* raiz = criarNo(vetor[meio]);
    raiz->left = montarArvore(vetor, esq, meio - 1);
    raiz->right = montarArvore(vetor, meio + 1, dir);
    return raiz;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    int tamanho = 0;
    int *valores = NULL;

    // aqui eu vou primeiro percorrer a arvore e guardar os valores
    // em um vetor, depois monto uma arvore balanceada de novo
    int *aux = malloc(1000 * sizeof(int));
    int idx = 0;
    salvarEmVetor(root, aux, &idx);

    valores = aux;
    tamanho = idx;

    return montarArvore(valores, 0, tamanho - 1);
}
