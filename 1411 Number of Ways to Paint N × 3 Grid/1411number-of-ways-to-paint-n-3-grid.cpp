class Solution {
public:
    const int MOD=1000000007;
    vector<vector<int>> dp;
    int func(vector<string> &row,int n,int idx){
        if(n<=0){return 1;}
        if(dp[n][idx]!=-1){return dp[n][idx];}
        int result=0;
        for(int i=0;i<12;i++){
            if(row[i][0]!=row[idx][0] && row[i][1]!=row[idx][1] && row[i][2]!=row[idx][2]){
                result=(result+func(row,n-1,i))%MOD;
            }
        }
        return dp[n][idx]=result;
    }

    int numOfWays(int n) {
        dp.assign(n,vector<int>(12,-1));
        vector<string> row={"RYG","RGY","GRY","GYR","YGR","YRG","RYR","RGR","GYG","GRG","YRY","YGY"};
        int result=0;
        for(int i=0;i<12;i++){
            result=(result+func(row,n-1,i))%MOD;
        }
        return result;
    }
};