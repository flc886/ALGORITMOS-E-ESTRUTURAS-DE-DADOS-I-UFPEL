#include <stdio.h>
#include <stdlib.h>

int* findDiagonalOrder( int** mat, int matSize, int* matColSize, int* returnSize )
{
    int linhas = matSize;
    int colunas = matColSize[0];
    int total = linhas * colunas;
    int* res = ( int* ) malloc( sizeof( int ) * total );
    int idx = 0;
    int i;
    int j;
    int soma;

    for ( soma = 0; soma <= linhas + colunas - 2; soma++ )
    {
        if ( soma % 2 == 0 )
        {
            for ( i = soma; i >= 0; i-- )
            {
                j = soma - i;

                if ( i < linhas && j < colunas )
                {
                    res[idx] = mat[i][j];
                    idx = idx + 1;
                }
            }
        }
        else
        {
            for ( i = 0; i <= soma; i++ )
            {
                j = soma - i;

                if ( i < linhas && j < colunas )
                {
                    res[idx] = mat[i][j];
                    idx = idx + 1;
                }
            }
        }
    }

    *returnSize = total;
    return res;
}

int main()
{
    int matSize = 3;
    int colSizeArr[3] = {3, 3, 3};
    int *matColSize = colSizeArr;

    int row0[] = {1,2,3};
    int row1[] = {4,5,6};
    int row2[] = {7,8,9};

    int *mat[3] = {row0, row1, row2};

    int returnSize;

    int *res = findDiagonalOrder(mat, matSize, matColSize, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", res[i]);
    }

    printf("\n");

    free(res);

    return 0;
}
