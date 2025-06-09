class Solution {
public:
    int func(string s1,string s2,int i,int j,vector<vector<int>> &dp){
        for(int m=1;m<=i;m++){
            for(int n=1;n<=j;n++){
                if(s1[m-1]==s2[n-1]){
                    dp[m][n]=1+dp[m-1][n-1];
                }
                else{
                    dp[m][n]=max(dp[m][n-1],dp[m-1][n]);
                }
            }
        }
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i=text1.size(),j=text2.size();
        vector<vector<int>> dp(i+1,vector<int>(j+1,0));
        int result=func(text1,text2,i,j,dp);
        return result;
    }
};