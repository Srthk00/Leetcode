class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> result(n,vector<int>(n,0));
        for(auto &q:queries){
            int r1=q[0];
            int c1=q[1];
            int r2=q[2];
            int c2=q[3];
            for(int i=r1;i<=r2;i++){
                result[i][c1]+=1;
                if(c2+1<n){
                    result[i][c2+1]-=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                result[i][j]=result[i][j]+result[i][j-1];
            }
        }
        return result;
    }
};