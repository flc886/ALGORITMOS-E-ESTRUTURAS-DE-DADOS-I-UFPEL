int searchInsert(int* nums, int numsSize, int target) {
    int idx = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == target){
            return i;
        }
        else if(nums[i] < target) {
            idx = i + 1;
        }
        else if (nums[i] > target){
            return idx;
        }
    }
    return idx;
}