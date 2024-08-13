int missingNumber(int* nums, int numsSize) {
    int total_sum=numsSize*(numsSize+1)/2;
    int array_sum=0;
    for(int i=0;i<numsSize;i++){
        array_sum+=nums[i];
    }
    int flag=total_sum-array_sum;
    return flag;
}