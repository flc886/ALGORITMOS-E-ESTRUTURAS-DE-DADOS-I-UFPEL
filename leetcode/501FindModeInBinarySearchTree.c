#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *resposta;
int qtd;
int atual;
int contador;
int melhor;

void dfs(struct TreeNode* root) {
    if(root == NULL) return;

    dfs(root->left);

    if(root->val == atual) {
        contador++;
    }
    else {
        atual = root->val;
        contador = 1;
    }

    if(contador > melhor) {
        melhor = contador;
        qtd = 1;
        resposta[0] = atual;
    }
    else if(contador == melhor) {
        resposta[qtd++] = atual;
    }

    dfs(root->right);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    resposta = malloc(1000 * sizeof(int));
    qtd = 0;
    atual = 0;
    contador = 0;
    melhor = 0;
    dfs(root);
    *returnSize = qtd;
    return resposta;
}
