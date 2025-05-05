class Solution {
public:    
    void makezero(vector<vector<int>> &grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        makezero(grid,i+1,j);
        makezero(grid,i,j+1);
        makezero(grid,i-1,j);
        makezero(grid,i,j-1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[0][i]){
                makezero(grid,0,i);
            }
            if(grid[m-1][i]){
                makezero(grid,m-1,i);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[j][0]){
                makezero(grid,j,0);
            }
            if(grid[j][n-1]){
                makezero(grid,j,n-1);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};