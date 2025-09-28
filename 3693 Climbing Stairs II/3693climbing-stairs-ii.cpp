class Solution {
public:
    int dp[100001];
    int cost(int i,vector<int> &costs,int n){
        if(i==n){return 0;}
        if(i>n){return 1e8;}
        if(dp[i]!=-1){return dp[i];}
        int one=1e9,two=1e9,three=1e9;
        if(i+1<=n){
            one=cost(i+1,costs,n)+costs[i]+1LL;
        }
        if(i+2<=n){
            two=cost(i+2,costs,n)+costs[i+1]+4LL;
        }
        if(i+3<=n){
            three=cost(i+3,costs,n)+costs[i+2]+9LL;
        }
        return dp[i]=min(one,min(two,three));
    }
    
    int climbStairs(int n, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return cost(0,costs,n);
    }
};