class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result=nums[0],curr=nums[0];
        for(int i=1;i<nums.size();i++){
            if(curr+nums[i]<nums[i]){
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