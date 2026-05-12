class Solution {
public:
    int func(vector<vector<int>> &tri,int i,int j,vector<vector<int>> &dp){
        if(i==tri.size()-1){
            return tri[i][j];
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int same=func(tri,i+1,j,dp);
        int next=func(tri,i+1,j+1,dp);
        return dp[i][j]=tri[i][j]+min(same,next);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(triangle[n-1].size(),INT_MAX));
        return func(triangle,0,0,dp);
    }
};