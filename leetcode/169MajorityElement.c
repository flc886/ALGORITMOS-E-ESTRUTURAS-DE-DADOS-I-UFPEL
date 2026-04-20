#include <stdlib.h>

int majorityElement(int* nums, int numsSize) {
    int candidato = nums[0];
    int contagem = 0;

    for(int i = 0; i < numsSize; i++) {
        if(contagem == 0) {
            candidato = nums[i];
            contagem = 1;
        }
        else if(nums[i] == candidato) {
            contagem++;
        }
        else {
            contagem--;
        }
    }

    return candidato;
}
