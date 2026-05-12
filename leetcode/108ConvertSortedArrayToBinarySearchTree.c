#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* criarNo(int valor) {
    struct TreeNode *no = malloc(sizeof(struct TreeNode));
    no->val = valor;
    no->left = NULL;
    no->right = NULL;
    return no;
}

struct TreeNode* montar(int* nums, int esq, int dir) {
    if (esq > dir) {
        return NULL;
    }

    int meio = esq + (dir - esq) / 2;
    struct TreeNode* raiz = criarNo(nums[meio]);
    raiz->left = montar(nums, esq, meio - 1);
    raiz->right = montar(nums, meio + 1, dir);
    return raiz;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return montar(nums, 0, numsSize - 1);
}
