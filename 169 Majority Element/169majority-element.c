int majorityElement(int* nums, int numsSize) {
    int count=0,element;
    for(int i=0;i<numsSize;i++){
        if(count==0){
            element=nums[i];
            count++;
        }
        else{
            if(nums[i]==element){
                count++;
            }
            else{
                count--;
            }
        }
    }
    return element;
}