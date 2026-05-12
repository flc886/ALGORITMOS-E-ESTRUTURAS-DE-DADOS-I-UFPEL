#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int contador = 0;
int resposta = 0;

void dfs(struct TreeNode* raiz, int k) {
    if(raiz == NULL) return;

    dfs(raiz->left, k);
    contador++;

    if(contador == k) {
        resposta = raiz->val;
        return;
    }

    dfs(raiz->right, k);
}

int kthSmallest(struct TreeNode* root, int k) {
    contador = 0;
    resposta = 0;
    dfs(root, k);
    return resposta;
}
