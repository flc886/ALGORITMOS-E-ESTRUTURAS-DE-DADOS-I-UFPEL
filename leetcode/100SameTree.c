#include<stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* arvore1, struct TreeNode* arvore2) {
    if (arvore1 == NULL && arvore2 == NULL) {
        return true;
    }
    if (arvore1 == NULL || arvore2 == NULL) {
        return false;
    }
    if (arvore1->val != arvore2->val) {
        return false;
    }
    return isSameTree(arvore1->left, arvore2->left) && isSameTree(arvore1->right, arvore2->right);
}
