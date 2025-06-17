class Solution {
public:
    int func(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(i>=grid.size() || j>=grid[0].size()){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=func(grid,i,j+1,dp);
        int down=func(grid,i+1,j,dp);
        return dp[i][j]=grid[i][j]+min(down,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(grid[0].size(),-1));
        return func(grid,0,0,dp);
    }
};