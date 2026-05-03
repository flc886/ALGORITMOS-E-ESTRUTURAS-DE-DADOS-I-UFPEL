#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void nextPermutation(int* nums, int numsSize) {
    for(int i = numsSize - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            for(int j = numsSize - 1; j > i; j--) {
                if(nums[j] > nums[i]) {
                    swap(&nums[i], &nums[j]);
                    break;
                }
            }
            break;
        }
    }

    for(int i = 0; i < numsSize / 2; i++) {
        swap(&nums[i], &nums[numsSize - 1 - i]);
    }
}
