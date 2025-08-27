class Solution {
private:
    int m,n;
    vector<vector<int>> dir={{-1,-1},{-1,1},{1,1},{1,-1}};
public:
    bool safe(int i,int j){
        if(i<0 || j<0 || i>=m || j>=n){return false;}
        return true;
    }

    int traverse(int i,int j,int pattern,vector<vector<int>> &grid,bool changedir,int d){
        int ni=i+dir[d][0];
        int nj=j+dir[d][1];
        int result=0;
        // can only explore if safe and also follow 2,0,2,0..... pattern
        if(safe(ni,nj) && grid[ni][nj]==pattern){
            // first find max len in direction of initial diagonal
            int samedir=1+traverse(ni,nj,pattern==2?0:2,grid,changedir,d);
            result=max(result,samedir); // stores current max len in same direction
            // then explore max len after the 90 degree(d+1) turn
            if(changedir){
                int newdir=max(result,1+traverse(ni,nj,pattern==2?0:2,grid,false,d<3?d+1:0));
                result=max(result,newdir);
            }
        }
        else{
            return 0;
        }
        return result;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    // explore all 4 initial diagonals
                    for(int d=0;d<4;d++){
                        result=max(result,1+traverse(i,j,2,grid,true,d));
                    }
                }
            }
        }
        return result;
    }
};