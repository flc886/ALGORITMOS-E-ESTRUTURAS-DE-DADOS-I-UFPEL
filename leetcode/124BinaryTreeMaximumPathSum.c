#include<limits.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxGain(struct TreeNode* raiz, int* maximoSoma) {
    if (raiz == NULL) {
        return 0;
    }
    int esquerda = maxGain(raiz->left, maximoSoma);
    int direita = maxGain(raiz->right, maximoSoma);
    if (esquerda < 0) esquerda = 0;
    if (direita < 0) direita = 0;
    int somaNovoCaminho = raiz->val + esquerda + direita;
    if (somaNovoCaminho > *maximoSoma) {
        *maximoSoma = somaNovoCaminho;
    }
    return raiz->val + (esquerda > direita ? esquerda : direita);
}

int maxPathSum(struct TreeNode* raiz) {
    int maximoSoma = INT_MIN;
    maxGain(raiz, &maximoSoma);
    return maximoSoma;
}
