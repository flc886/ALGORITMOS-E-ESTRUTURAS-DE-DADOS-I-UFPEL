#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool temCaminho(struct TreeNode* root, int soma, int alvo) {
    if(root == NULL) return false;

    soma += root->val;
    if(root->left == NULL && root->right == NULL) {
        return soma == alvo;
    }

    return temCaminho(root->left, soma, alvo) || temCaminho(root->right, soma, alvo);
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    return temCaminho(root, 0, targetSum);
}
