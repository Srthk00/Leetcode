class Solution {
    void rotate(vector<vector<int>> &mat){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<i;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<mat.size();i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target){return true;}
        for(int i=0;i<4;i++){
            if(mat==target){return true;}
            rotate(mat);
        }
        return false;
    }
};