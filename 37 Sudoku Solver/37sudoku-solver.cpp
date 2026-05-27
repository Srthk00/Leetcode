class Solution {
public:
    bool isvalid(vector<vector<char>> &grid,int i,int j,char num){
        for(int x=0;x<9;x++){
            if(grid[i][x]==num){return false;}
        }
        for(int x=0;x<9;x++){
            if(grid[x][j]==num){return false;}
        }
        int bi=(i/3)*3,bj=(j/3)*3;
        for(int a=bi;a<bi+3;a++){
            for(int b=bj;b<bj+3;b++){
                if(grid[a][b]==num){return false;}
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &grid){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(grid[i][j]!='.'){continue;}
                for(char a='1';a<='9';a++){
                    if(isvalid(grid,i,j,a)){
                        grid[i][j]=a;
                        if(solve(grid)){
                           return true; 
                        }
                        grid[i][j]='.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool flag=solve(board);
    }
};