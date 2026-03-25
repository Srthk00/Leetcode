class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<long long> rowSum(m,0);
        vector<long long> colSum(n,0);
        long long sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rowSum[i]+=grid[i][j];
                colSum[j]+=grid[i][j];
                sum+=grid[i][j];
            }
        }
        long long left=rowSum[0];
        for(int i=1;i<m;i++){
            if(left==sum-left){
                return true;
            }
            left+=rowSum[i];
        }
        left=colSum[0];
        for(int i=1;i<n;i++){
            if(left==sum-left){
                return true;
            }
            left+=colSum[i];
        }
        return false;
    }
};