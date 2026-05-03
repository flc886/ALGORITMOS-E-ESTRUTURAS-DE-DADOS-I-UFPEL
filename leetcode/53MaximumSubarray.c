#include <limits.h>

int maxSubArray(int* nums, int numsSize) {
    int atual = nums[0];
    int melhor = nums[0];

    for(int i = 1; i < numsSize; i++) {
        if(atual < 0) {
            atual = nums[i];
        }
        else {
            atual += nums[i];
        }

        if(atual > melhor) {
            melhor = atual;
        }
    }

    return melhor;
}
