class Solution {
public:
    bool isvalid(vector<vector<int>> &grid,int i,int j){
        int visited[10]={false};
        for(int x=i;x<i+3;x++){
            for(int y=j;y<j+3;y++){
                if(grid[x][y]>0 && grid[x][y]<10 && !visited[grid[x][y]]){visited[grid[x][y]]=true;}
                else{return false;}
            }
        }
        int c1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
        int c2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
        int c3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
        
        int r1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
        int r2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
        int r3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];

        int d1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        int d2=grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2];
        unordered_set<int> st={r1,r2,r3,c1,c2,c3,d1,d2};
        if(st.size()==1){return true;}
        return false;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int result=0;
        if(m<3 || n<3){return 0;}
        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                if(isvalid(grid,i,j)){result++;}
            }
        }
        return result;
    }
};