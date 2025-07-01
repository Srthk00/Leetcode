class Solution {
public:
    vector<vector<int>> dp;
    int func(int n,int len,int clip){
        if(len==n){
            return dp[len][clip]=0;
        }
        if(len>n){
            return dp[len][clip]=1000;
        }
        if(dp[len][clip]!=-1){
            return dp[len][clip];
        }
        int copy=1+1+func(n,len+len,len);
        int paste=1+func(n,len+clip,clip);
        return dp[len][clip]=min(copy,paste);
    }

    int minSteps(int n) {
        if(n==1){return 0;}
        dp=vector<vector<int>>(2*n+1,vector<int>(2*n+1,-1));
        return 1+func(n,1,1);
    }
};