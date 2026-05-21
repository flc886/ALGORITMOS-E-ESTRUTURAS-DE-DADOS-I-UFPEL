#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int resultado = INT_MAX;
int anterior = 0;
bool primeiro = true;

void aux(struct TreeNode* raiz) {
    if(raiz == NULL) return;

    aux(raiz->left);

    if(!primeiro) {
        if(raiz->val - anterior < resultado) {
            resultado = raiz->val - anterior;
        }
    }
    else {
        primeiro = false;
    }

    anterior = raiz->val;
    aux(raiz->right);
}

int getMinimumDifference(struct TreeNode* root) {
    resultado = INT_MAX;
    anterior = 0;
    primeiro = true;
    aux(root);
    return resultado;
}
