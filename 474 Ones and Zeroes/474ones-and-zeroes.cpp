class Solution {
public:
    //[position/index of strs][m][n]
    int dp[601][101][101];

    int count1(string &str){
        int count=0;
        for(char ch:str){if(ch=='1'){count++;}}
        return count;
    }

    int func(vector<string> &strs,int m,int n,int i){
        if(i>=strs.size()){
            return 0;
        }
        if(dp[i][m][n]!=-1){return dp[i][m][n];}
        int ones=count1(strs[i]);
        int zeros=strs[i].size()-ones;
        int take=0,donttake=0;
        if(m>=zeros && n>=ones){
            take=1+func(strs,m-zeros,n-ones,i+1);
        }
        donttake=func(strs,m,n,i+1);
        return dp[i][m][n]=max(take,donttake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return func(strs,m,n,0);
    }
};