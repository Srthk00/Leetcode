class Solution {
public:
    vector<vector<int>> dp;

    int func(vector<int> &nums,int amount,int i){
        if(amount==0){return 1;}
        if(i>=nums.size() || amount<0){return 0;}
        if(dp[amount][i]!=-1){return dp[amount][i];}
        int take=func(nums,amount-nums[i],i);
        int skip=func(nums,amount,i+1);
        return dp[amount][i]=take+skip;
    }

    int change(int amount, vector<int>& coins) {
        dp.assign(amount+1,vector<int>(coins.size()+1,-1));
        return func(coins,amount,0);
    }
};