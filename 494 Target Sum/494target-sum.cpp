class Solution {
public:
    int assign(int i,vector<int> &nums,int target){
        if(i>=nums.size()){
            if(target==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        int negative=assign(i+1,nums,target-nums[i]);
        int positive=assign(i+1,nums,target+nums[i]);
        return negative+positive;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int result=assign(0,nums,target);
        return result;
    }
};