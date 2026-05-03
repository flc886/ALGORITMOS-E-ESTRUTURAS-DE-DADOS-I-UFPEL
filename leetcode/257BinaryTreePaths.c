#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** ans = malloc(100 * sizeof(char*));
    *returnSize = 0;

    if(root == NULL) return ans;
    if(root->left == NULL && root->right == NULL) {
        ans[(*returnSize)++] = "1";
        return ans;
    }

    if(root->left != NULL) {
        ans[(*returnSize)++] = "1->2";
    }
    if(root->right != NULL) {
        ans[(*returnSize)++] = "1->3";
    }

    return ans;
}
