/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* raiz, struct TreeNode* no1, struct TreeNode* no2) {
    if (raiz == NULL || raiz == no1 || raiz == no2) {
        return raiz;
    }
    struct TreeNode* esquerda = lowestCommonAncestor(raiz->left, no1, no2);
    struct TreeNode* direita = lowestCommonAncestor(raiz->right, no1, no2);
    if (esquerda != NULL && direita != NULL) {
        return raiz;
    }
    return esquerda != NULL ? esquerda : direita;
}
