class Solution {
public:
    int m,n;

    void row(int x,vector<vector<int>>& matrix){
        for(int j=0;j<n;j++){
            matrix[x][j]=0;
        }
    }

    void col(int x,vector<vector<int>>& matrix){
        for(int i=0;i<m;i++){
            matrix[i][x]=0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<pair<int,int>> track;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!matrix[i][j]){
                    track.push_back({i,j});
                }
            }
        }
        for(auto it:track){
            row(it.first,matrix);
            col(it.second,matrix);
        }
    }
};