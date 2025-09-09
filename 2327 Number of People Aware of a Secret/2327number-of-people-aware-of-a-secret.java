class Solution {
    final int MOD=1000000007;
    Integer[] dp;
    int solve(int n, int delay, int forget){
        if(n==1){return 1;}
        if(dp[n]!=-1){return dp[n];}
        int result=0;
        for(int i=n-forget+1;i<=n-delay;i++){
            if(i>0){
                result=(result+solve(i,delay,forget))%MOD;
            }
        }
        return dp[n]=result;
    }

    public int peopleAwareOfSecret(int n, int delay, int forget) {
        int result=0;
        dp=new Integer[n+1];
        Arrays.fill(dp,-1);
        for(int i=n-forget+1;i<=n;i++){
            if(i>0){
                result=(result+solve(i,delay,forget))%MOD;
            }
        }
        return result;
    }
}