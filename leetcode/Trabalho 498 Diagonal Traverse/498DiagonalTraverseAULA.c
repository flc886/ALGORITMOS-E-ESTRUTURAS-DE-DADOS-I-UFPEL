int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int linhas = matSize;
    int colunas = matColSize[0];
    int total = linhas * colunas;
    int *res = (int *)malloc(sizeof(int) * total);
    int idx = 0;
    int i, j, soma;

    for (soma = 0; soma <= linhas + colunas - 2; soma++) {
        if (soma % 2 == 0) {
            for (i = soma; i >= 0; i--) {
                j = soma - i;
                if (i < linhas && j < colunas) {
                    res[idx] = mat[i][j];
                    idx = idx + 1;
                }
            }
        } else {
            for (i = 0; i <= soma; i++) {
                j = soma - i;
                if (i < linhas && j < colunas) {
                    res[idx] = mat[i][j];
                    idx = idx + 1;
                }
            }
        }
    }

    *returnSize = total;
    return res;
}