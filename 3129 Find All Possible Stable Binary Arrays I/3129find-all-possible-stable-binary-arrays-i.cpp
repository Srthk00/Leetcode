class Solution {
public:
    int mod=1e9+7;
    int dp[201][201][2];

    int func(int zero,int one,int lastone,int limit){
        if(zero==0 && one==0){return 1;}
        if(dp[zero][one][lastone]!=-1){return dp[zero][one][lastone];}
        int result=0;
        if(lastone){
            for(int i=1;i<=min(limit,zero);i++){
                result=(result+func(zero-i,one,0,limit))%mod;
            }
        }
        else{
            for(int i=1;i<=min(limit,one);i++){
                result=(result+func(zero,one-i,1,limit))%mod;
            }
        }
        return dp[zero][one][lastone]=result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int startWithOne=func(zero,one,0,limit);
        int startWithZero=func(zero,one,1,limit);
        return (startWithOne+startWithZero)%mod;
    }
};