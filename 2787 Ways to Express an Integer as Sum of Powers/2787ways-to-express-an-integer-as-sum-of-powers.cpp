class Solution {
public:
    vector<vector<int>> dp;
    long long power(int base,int expo){
        if(expo==0){return 1;}
        long long temp=power(base,expo/2);
        if(expo%2==0){
            return temp*temp;
        }
        else{
            return base*temp*temp;
        }
    }
    int func(int n,int k,int i){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        long long temp=power(i,k);
        if(n-temp<0){
            return 0;
        }
        return dp[n][i]=((func(n-(int)temp,k,i+1)+func(n,k,i+1))%1000000007);
    }
    int numberOfWays(int n, int x) {
        dp=vector<vector<int>>(n+1,vector<int>(302,-1));
        return func(n,x,1);
    }
};