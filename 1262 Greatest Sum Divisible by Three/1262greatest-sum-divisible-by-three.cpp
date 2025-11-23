class Solution {
public:
    vector<vector<long long>> dp;

    long long func(vector<int> &nums,int idx,long long sum){
        if(idx>=nums.size()){
            if(sum==0){return dp[idx][sum]=0;}
            return dp[idx][sum]=-1e9;
        }
        if(dp[idx][sum]!=-1){return dp[idx][sum];}
        long long result=sum;
        long long take=nums[idx]+func(nums,idx+1,(sum+nums[idx])%3);
        long long donttake=func(nums,idx+1,sum);
        return dp[idx][sum]=max(take,donttake);
    }

    int maxSumDivThree(vector<int>& nums) {
        dp=vector<vector<long long>>(nums.size()+1,vector<long long>(3,-1));
        return max(0,(int)func(nums,0,0));
    }
};