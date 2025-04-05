class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]){
                    if(i==row-1 || !grid[i+1][j]){
                        peri++;
                    }
                    if(i==0 || !grid[i-1][j]){
                        peri++;
                    }
                    if(j==col-1 || !grid[i][j+1]){
                        peri++;
                    }
                    if(j==0 || !grid[i][j-1]){
                        peri++;
                    }
                }
            }
        }
        return peri;
    }
};