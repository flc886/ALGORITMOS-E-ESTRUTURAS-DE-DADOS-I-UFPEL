/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* searchBST(struct TreeNode* raiz, int valor) {
    while (raiz != NULL) {
        if (raiz->val == valor) {
            return raiz;
        }
        else if (valor < raiz->val) {
            raiz = raiz->left;
        }
        else {
            raiz = raiz->right;
        }
    }
    return NULL;
}
