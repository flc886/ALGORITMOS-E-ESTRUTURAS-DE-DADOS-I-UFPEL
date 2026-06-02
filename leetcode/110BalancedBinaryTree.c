#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int altura(struct TreeNode* raiz, int *balanceada) {
    if(raiz == NULL) return 0;

    int esq = altura(raiz->left, balanceada);
    int dir = altura(raiz->right, balanceada);

    if(abs(esq - dir) > 1) {
        *balanceada = 0;
    }

    return 1 + (esq > dir ? esq : dir);
}

bool isBalanced(struct TreeNode* root) {
    int balanceada = 1;
    altura(root, &balanceada);
    return balanceada;
}
