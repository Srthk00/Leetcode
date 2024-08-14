int search(int* nums, int numsSize, int target) {
    int start=0,end=numsSize-1,diff;
    while(start<=end){
        diff=(end+start)/2;
        if(nums[diff]==target){
            return diff;
        }
        else if(nums[diff]<target){
            start=diff+1;
        }
        else{
            end=diff-1;
        }
    }
    return -1;
}