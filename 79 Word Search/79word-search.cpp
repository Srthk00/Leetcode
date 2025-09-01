class Solution {
public:
    int m,n;
    bool traverse(vector<vector<char>> &board,vector<vector<bool>> &visited,int i,int j,int idx,string word){
        if(i<0 || j<0 || i>=m || j>=n || visited[i][j] || board[i][j]!=word[idx]){
            return false;
        }
        visited[i][j]=true;
        if(idx==word.size()-1){
            return true;
        }
        bool result=traverse(board,visited,i+1,j,idx+1,word)||
                    traverse(board,visited,i-1,j,idx+1,word)||
                    traverse(board,visited,i,j+1,idx+1,word)||
                    traverse(board,visited,i,j-1,idx+1,word);
        visited[i][j]=false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    visited[i][j]=true;
                    if(word.size()==1){return true;}
                    if(traverse(board,visited,i+1,j,1,word)||
                    traverse(board,visited,i-1,j,1,word)||
                    traverse(board,visited,i,j+1,1,word)||
                    traverse(board,visited,i,j-1,1,word)){
                        return true;
                    }
                }
                visited[i][j]=false;
            }
        }
        return false;
    }
};