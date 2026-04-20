#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int resposta = 0;

    for(int i = 0; i < numsSize; i++) {
        resposta ^= nums[i];
    }

    return resposta;
}
