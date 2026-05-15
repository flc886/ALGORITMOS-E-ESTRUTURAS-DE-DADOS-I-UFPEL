#include<stdlib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int** levelOrder(struct TreeNode* raiz, int* returnSize, int** returnColumnSizes) {
    if (raiz == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct TreeNode* fila[1000];
    int frente = 0, fim = 0;
    fila[fim++] = raiz;

    int** resultado = malloc(1000 * sizeof(int*));
    int* colunas = malloc(1000 * sizeof(int));
    int niveis = 0;

    while (frente < fim) {
        int tamanho = fim - frente;
        int* linha = malloc(tamanho * sizeof(int));
        colunas[niveis] = tamanho;
        for (int i = 0; i < tamanho; i++) {
            struct TreeNode* no = fila[frente++];
            linha[i] = no->val;
            if (no->left) {
                fila[fim++] = no->left;
            }
            if (no->right) {
                fila[fim++] = no->right;
            }
        }
        resultado[niveis++] = linha;
    }

    *returnSize = niveis;
    *returnColumnSizes = colunas;
    return resultado;
}
