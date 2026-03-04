class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int> row(m,0);
        for(int i=0;i<m;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]){row[i]++;}
            }
        }
        vector<int> col(n,0);
        for(int j=0;j<n;j++){
            int c=0;
            for(int i=0;i<m;i++){
                if(mat[i][j]){col[j]++;}
            }
        }
        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] && row[i]==1 && col[j]==1){result++;}
            }
        }
        return result;
    }
};