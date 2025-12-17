class Solution {
public:
    // 0-> no transaction
    // 1-> normal
    // 2-> short
    long long dp[1001][501][3];
    long long dfs(vector<int> &nums,int i,int k,int state){
        if(i==nums.size() && state==0){
            return 0;
        }
        if(i==nums.size() && state!=0){
            return -1e9;
        }
        if(dp[i][k][state]!=-1){return dp[i][k][state];}
        long long ans=-1e18;
        if(state==0){
            ans=max(ans,dfs(nums,i+1,k,state));
            ans=max(ans,(dfs(nums,i+1,k,1)-nums[i]));
            ans=max(ans,dfs(nums,i+1,k,2)+nums[i]);
        }
        else if(state==1 && k>0){
            ans=max(ans,dfs(nums,i+1,k,state));
            ans=max(ans,(dfs(nums,i+1,k-1,0)+nums[i]));
        }
        else if(state==2 && k>0){
            ans=max(ans,dfs(nums,i+1,k,state));
            ans=max(ans,(dfs(nums,i+1,k-1,0)-nums[i]));
        }
        return dp[i][k][state]=ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp,-1,sizeof(dp));
        return dfs(prices,0,k,0);
    }
};