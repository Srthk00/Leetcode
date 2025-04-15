class Solution {
public:
    int dfs(vector<vector<int>> &grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0)
            return 0;
        int num=grid[i][j];
        grid[i][j]=0;
        return num+dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maximum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    int curr=dfs(grid,i,j);
                    maximum=max(curr,maximum);
                }
            }
        }
        return maximum;
    }
};