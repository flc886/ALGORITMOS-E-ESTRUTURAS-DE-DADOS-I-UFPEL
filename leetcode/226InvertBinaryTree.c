/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* invertTree(struct TreeNode* raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    struct TreeNode* temporario = raiz->left;
    raiz->left = invertTree(raiz->right);
    raiz->right = invertTree(temporario);
    return raiz;
}
