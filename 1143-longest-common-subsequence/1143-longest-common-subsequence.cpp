class Solution {
public:
    int m,n;
    vector<vector<int>> dp;

    int solve(int i,int j,string &str1,string &str2){
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int temp=0;
        if(str1[i]==str2[j]){
            return dp[i][j]=1+solve(i+1,j+1,str1,str2);
        }
        return dp[i][j]=max(solve(i+1,j,str1,str2),solve(i,j+1,str1,str2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        m=text1.size();
        n=text2.size();
        dp=vector<vector<int>>(m+1,vector<int>(n+1,-1));
        return solve(0,0,text1,text2);
    }
};