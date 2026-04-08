#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* root, int* ans, int* size) {
    if(root == NULL) return;

    dfs(root->left, ans, size);
    ans[(*size)++] = root->val;
    dfs(root->right, ans, size);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(1000 * sizeof(int));
    *returnSize = 0;
    dfs(root, ans, returnSize);
    return ans;
}
