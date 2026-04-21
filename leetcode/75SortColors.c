#include <stdlib.h>

void sortColors(int* nums, int numsSize) {
    int cont0 = 0;
    int cont1 = 0;
    int cont2 = 0;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 0) cont0++;
        else if(nums[i] == 1) cont1++;
        else cont2++;
    }

    for(int i = 0; i < cont0; i++) nums[i] = 0;
    for(int i = cont0; i < cont0 + cont1; i++) nums[i] = 1;
    for(int i = cont0 + cont1; i < numsSize; i++) nums[i] = 2;
}
