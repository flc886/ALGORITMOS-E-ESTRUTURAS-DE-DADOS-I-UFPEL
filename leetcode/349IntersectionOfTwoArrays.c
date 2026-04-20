#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), comparar);
    qsort(nums2, nums2Size, sizeof(int), comparar);

    int* resposta = malloc(1000 * sizeof(int));
    int k = 0;

    for(int i = 0; i < nums1Size; i++) {
        for(int j = 0; j < nums2Size; j++) {
            if(nums1[i] == nums2[j]) {
                resposta[k++] = nums1[i];
                break;
            }
        }
    }

    *returnSize = k;
    return resposta;
}
