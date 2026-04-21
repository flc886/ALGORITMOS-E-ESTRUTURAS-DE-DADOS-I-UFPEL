#include <stdlib.h>

void moveZeroes(int* nums, int numsSize) {
    int indice = 0;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != 0) {
            nums[indice] = nums[i];
            indice++;
        }
    }

    for(int i = indice; i < numsSize; i++) {
        nums[i] = 0;
    }
}
