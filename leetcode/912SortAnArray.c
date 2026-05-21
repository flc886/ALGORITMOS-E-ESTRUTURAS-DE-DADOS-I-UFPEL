#include <stdlib.h>

void trocar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void quickSort(int *nums, int esq, int dir) {
    if(esq >= dir) return;

    int pivo = nums[(esq + dir) / 2];
    int i = esq;
    int j = dir;

    while(i <= j) {
        while(nums[i] < pivo) i++;
        while(nums[j] > pivo) j--;

        if(i <= j) {
            trocar(&nums[i], &nums[j]);
            i++;
            j--;
        }
    }

    quickSort(nums, esq, j);
    quickSort(nums, i, dir);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    quickSort(nums, 0, numsSize - 1);
    *returnSize = numsSize;
    return nums;
}
