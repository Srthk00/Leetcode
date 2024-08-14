int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max=0,count=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==1){
            count++;
        }
        else{
            if(count>max){
                max=count;
            }
            count=0;
        }
    }
    if(count>max)
        max=count;
    return max;
}