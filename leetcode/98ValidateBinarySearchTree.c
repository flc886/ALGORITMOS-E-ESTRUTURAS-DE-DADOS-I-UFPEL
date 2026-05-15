#include<stdbool.h>
#include<limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool validar(struct TreeNode* raiz, long minimo, long maximo) {
    if (raiz == NULL) {
        return true;
    }
    if (raiz->val <= minimo || raiz->val >= maximo) {
        return false;
    }
    return validar(raiz->left, minimo, raiz->val) && validar(raiz->right, raiz->val, maximo);
}

bool isValidBST(struct TreeNode* raiz) {
    return validar(raiz, LONG_MIN, LONG_MAX);
}
