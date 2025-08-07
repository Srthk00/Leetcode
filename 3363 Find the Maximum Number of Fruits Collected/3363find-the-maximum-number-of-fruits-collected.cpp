class Solution {
private:
    int n;
    vector<vector<int>> dp;
public:
    int LEFT(int i,int j,vector<vector<int>> & grid){
        if(i<0 || i>=n || j<0 || j>=n){return 0;}
        if(i<=j){return 0;}
        if(i==n-1 && j==n-1){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int top=grid[i][j]+LEFT(i-1,j+1,grid);
        int right=grid[i][j]+LEFT(i,j+1,grid);
        int bottom=grid[i][j]+LEFT(i+1,j+1,grid);
        return dp[i][j]=max({top,right,bottom});
    }

    int TOP(int i,int j,vector<vector<int>> & grid){
        if(i<0 || i>=n || j<0 || j>=n){return 0;}
        if(i>=j){return 0;}
        if(i==n-1 && j==n-1){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int left=grid[i][j]+TOP(i+1,j-1,grid);
        int bottom=grid[i][j]+TOP(i+1,j,grid);
        int right=grid[i][j]+TOP(i+1,j+1,grid);
        return dp[i][j]=max({left,bottom,right});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        dp=vector<vector<int>>(n,vector<int>(n,-1));
        int child1=0,child2=0,child3=0;
        for(int i=0;i<n;i++){
            child2+=fruits[i][i];
        }
        child1=LEFT(n-1,0,fruits);
        child3=TOP(0,n-1,fruits);
        return child1+child2+child3;
    }
};