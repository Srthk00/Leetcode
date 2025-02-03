int max_incrr(int *nums,int SIZE){
    int curr=1,max=1;
    int i=1;
    while(i<SIZE){
        if(nums[i-1]<nums[i]){
            curr+=1;
            i++;
        }
        else{
            if(curr>max)
                max=curr;
            i++;
            curr=1;
        }
    }
    if(curr>max)
        max=curr;
    return max;
}

int max_decrr(int *nums,int SIZE){
    int curr=1,max=1;
    int i=1;
    while(i<SIZE){
        if(nums[i-1]>nums[i]){
            curr+=1;
            i++;
        }
        else{
            if(curr>max)
                max=curr;
            i++;
            curr=1;
        }
    }
    if(curr>max)
        max=curr;
    return max;
}

int longestMonotonicSubarray(int* nums, int numsSize) {
    if(numsSize==0) 
        return 0;
    int i=max_incrr(nums,numsSize);
    int d=max_decrr(nums,numsSize);
    if(i<=d)
        return d;
    else
        return i;
}