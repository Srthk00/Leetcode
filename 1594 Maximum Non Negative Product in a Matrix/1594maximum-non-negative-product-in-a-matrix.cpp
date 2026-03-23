class Solution {
public:
    vector<vector<int>> g;
    int m,n;
    long long result=-1;

    void solve(int i, int j, long long prod){
        if(i>=m || j>=n){
            return;
        }
        if(g[i][j]==0){
            result=max(result,0LL);
            return;
        }
        prod*=g[i][j];
        if(i==m-1 && j==n-1){
            result=max(result,prod);
            return;
        }
        solve(i+1,j,prod);
        solve(i,j+1,prod);
    }

    int maxProductPath(vector<vector<int>>& grid) {
        g=grid;
        m=grid.size(),n=grid[0].size();
        solve(0,0,1LL);
         return result<0?-1:(int)(result%(1000000007));
    }
};