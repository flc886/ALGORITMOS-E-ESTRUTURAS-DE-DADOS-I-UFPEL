int search(int* nums, int numsSize, int target) {
    int esq = 0;
    int dir = numsSize - 1;

    while(esq <= dir) {
        int meio = esq + (dir - esq) / 2;

        if(nums[meio] == target) {
            return meio;
        }
        else if(nums[meio] < target) {
            esq = meio + 1;
        }
        else {
            dir = meio - 1;
        }
    }

    return -1;
}
