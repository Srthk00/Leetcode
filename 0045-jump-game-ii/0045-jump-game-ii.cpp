class Solution {
public:
    vector<int> dp;

    int solve(int i,vector<int> &nums){
        if(i>=nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int n=nums[i];
        int result=1e9;
        for(int j=i+1;j<nums.size() && j<=i+n;j++){
            result=min(result,1+solve(j,nums));
        }
        return dp[i]=result;
    }

    int jump(vector<int>& nums) {
        dp=vector<int>(nums.size(),-1);
        return solve(0,nums);
    }
};