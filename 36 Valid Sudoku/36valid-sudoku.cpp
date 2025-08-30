class Solution {
public:
    bool isvalidrow(vector<vector<char>>& grid,int i){
        unordered_set<char> st;
        for(int j=0;j<9;j++){
            if(grid[i][j]=='.'){continue;}
            if(st.find(grid[i][j])!=st.end()){
                return false;
            }
            st.insert(grid[i][j]);
        }
        return true;
    }

    bool isvalidcol(vector<vector<char>>& grid,int i){
        unordered_set<char> st;
        for(int j=0;j<9;j++){
            if(grid[j][i]=='.'){continue;}
            if(st.find(grid[j][i])!=st.end()){
                return false;
            }
            st.insert(grid[j][i]);
        }
        return true;
    }

    bool isvalidbox(vector<vector<char>>& grid,int p,int q){
        unordered_set<char> st;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                char val=grid[p+i][q+j];
                if(val=='.'){
                    continue;
                }
                if(st.find(val)!=st.end()){
                    return false;
                }
                st.insert(val);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            if(!isvalidrow(board,i)){
                return false;
            }
            if(!isvalidcol(board,i)){
                return false;
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(!isvalidbox(board,i,j)){
                    return false;
                }
            }
        }
        return true;
    }
};