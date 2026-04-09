class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=nums[0],result=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>(curr+nums[i])){
                curr=nums[i];
            }
            else{
                curr+=nums[i];
            }
            result=max(result,curr);
        }
        return result;
    }
};