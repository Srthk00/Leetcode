class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            int j=0;
            while(j<n && grid[i][j]>=0){
                j++;
            }
            count+=n-j;
        }
        return count;
    }
};