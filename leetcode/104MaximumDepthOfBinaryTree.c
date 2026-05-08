/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int alturaEsq = maxDepth(root->left);
    int alturaDir = maxDepth(root->right);

    if (alturaEsq > alturaDir)
    {
        return alturaEsq + 1;
    }
    else
    {
        return alturaDir + 1;
    }
}