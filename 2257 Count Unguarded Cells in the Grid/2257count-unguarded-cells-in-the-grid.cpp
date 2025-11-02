class Solution {
public:
    void mark(vector<vector<int>> &grid,int i,int j,int m,int n){
        for(int a=j-1;a>=0;a--){
            if(grid[i][a]==1 || grid[i][a]==2){break;}
            grid[i][a]=3;
        }
        for(int a=j+1;a<n;a++){
            if(grid[i][a]==1 || grid[i][a]==2){break;}
            grid[i][a]=3;
        }
        for(int a=i-1;a>=0;a--){
            if(grid[a][j]==1 || grid[a][j]==2){break;}
            grid[a][j]=3;
        }
        for(int a=i+1;a<m;a++){
            if(grid[a][j]==1 || grid[a][j]==2){break;}
            grid[a][j]=3;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(auto &it:walls){
            int i=it[0];
            int j=it[1];
            grid[i][j]=1;
        }
        for(auto &it:guards){
            int i=it[0];
            int j=it[1];
            grid[i][j]=2;
        }
        for(auto &it:guards){
            int i=it[0];
            int j=it[1];
           mark(grid,i,j,m,n);
        }
        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){result++;}
            }
        }
        return result;
    }
};