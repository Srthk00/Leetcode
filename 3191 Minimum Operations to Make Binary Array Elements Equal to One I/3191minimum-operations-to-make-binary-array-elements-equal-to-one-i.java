class Solution {
    public int minOperations(int[] nums) {
        int low=0,high=2;
        int count=0;
        while(high<nums.length){
            if(nums[low]==0){
                nums[low]^=1;
                nums[low+1]^=1;
                nums[low+2]^=1;
                count++;
            }
            low++;
            high++;
        }
        if(nums[low]==1 && nums[low+1]==1)
            return count;
        return -1;
    }
}