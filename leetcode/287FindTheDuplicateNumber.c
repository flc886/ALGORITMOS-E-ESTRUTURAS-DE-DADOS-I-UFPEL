#include <stdlib.h>

int findDuplicate(int* nums, int numsSize) {
    int* visto = calloc(numsSize, sizeof(int));

    for(int i = 0; i < numsSize; i++) {
        if(visto[nums[i]] == 1) {
            return nums[i];
        }
        visto[nums[i]] = 1;
    }

    return -1;
}
