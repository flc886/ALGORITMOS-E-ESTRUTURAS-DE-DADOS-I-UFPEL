#include<stdlib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* insertIntoBST(struct TreeNode* raiz, int valor) {
    if (raiz == NULL) {
        struct TreeNode* novoNo = malloc(sizeof(struct TreeNode));
        novoNo->val = valor;
        novoNo->left = NULL;
        novoNo->right = NULL;
        return novoNo;
    }
    if (valor < raiz->val) {
        raiz->left = insertIntoBST(raiz->left, valor);
    } else {
        raiz->right = insertIntoBST(raiz->right, valor);
    }
    return raiz;
}
