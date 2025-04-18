class Solution {
public:
    bool dfs(vector<vector<int>> &grid1,vector<vector<int>> &grid2,int i,int j,vector<vector<int>> &visited){
        int m=grid2.size();
        int n=grid2[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid2[i][j]==0 || visited[i][j]==1){
            return true;
        }
        visited[i][j]=1;
        bool flag=true;
        if(grid1[i][j]==0){
            flag=false;
        }
        bool d1=dfs(grid1,grid2,i+1,j,visited);
        bool d2=dfs(grid1,grid2,i-1,j,visited);
        bool d3=dfs(grid1,grid2,i,j+1,visited);
        bool d4=dfs(grid1,grid2,i,j-1,visited);
        return flag && d1 && d2 && d3 && d4;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count=0;
        vector<vector<int>> visited(grid1.size(),vector<int> (grid1[0].size(),0));
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                if(visited[i][j]==0 && grid2[i][j]){
                    if(dfs(grid1,grid2,i,j,visited)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};