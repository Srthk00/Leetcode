class Solution {
private:
    vector<vector<int>> dp;

public:
    int findmax(int i,vector<int> &nums,int target){
        if(target==0){
            return 0;
        }
        if(i>=nums.size() || target<0){
            return INT_MIN;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int dont=findmax(i+1,nums,target);
        int take=1+findmax(i+1,nums,target-nums[i]);
        return dp[i][target]=max(dont,take);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        dp=vector<vector<int>>(n+1,vector<int>(target+1,-1));
        int result=findmax(0,nums,target);
        return result<=0?-1:result;
    }
};