class Solution {
private:
    vector<vector<int>> dp;
public:
    int func(vector<vector<int>> &matrix,int i,int j,int n){
        if(j<0 || j>=n){return 1e9;}
        if(dp[i][j]!=INT_MIN){return dp[i][j];}
        if(i==n-1){return matrix[i][j];}
        int left=matrix[i][j]+func(matrix,i+1,j-1,n);
        int bottom=matrix[i][j]+func(matrix,i+1,j,n);
        int right=matrix[i][j]+func(matrix,i+1,j+1,n);
        return dp[i][j]=min({left,bottom,right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        dp=vector<vector<int>>(n+1,vector<int>(n+1,INT_MIN));
        int result=INT_MAX;
        for(int j=0;j<n;j++){
            result=min(result,func(matrix,0,j,n));
        }
        return result;
    }
};