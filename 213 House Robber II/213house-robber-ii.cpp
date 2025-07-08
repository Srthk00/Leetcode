class Solution {
public:
    vector<int> dp;
    int func(vector<int> &nums,int i, int n){
        if(i>n){return 0;}
        if(dp[i]!=-1){return dp[i];}
        if(i==n){return dp[i]=nums[i];}
        int rob=nums[i]+func(nums,i+2,n);
        int dontrob=func(nums,i+1,n);
        return dp[i]=max(rob,dontrob);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return nums[0];}
        dp=vector<int>(n,-1);
        int take1=func(nums,0,n-2);
        fill(dp.begin(),dp.end(),-1);
        int take2=func(nums,1,n-1);
        return max(take1,take2);
    }
};