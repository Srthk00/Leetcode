class Solution {
public:
    int maxSideLength(vector<vector<int>>& grid, int threshold) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> prefix(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                prefix[i][j]=grid[i][j]+(i-1>=0?prefix[i-1][j]:0)+(j-1>=0?prefix[i][j-1]:0)-((i-1>=0 && j-1>=0)?prefix[i-1][j-1]:0);
            }
        }
        int result=0;
        for(int k=0;k<min(m,n);k++){
            for(int i=0;i+k<m;i++){
                for(int j=0;j+k<n;j++){
                    int ei=i+k,ej=j+k;
                    int sum=prefix[ei][ej]-(i-1>=0?prefix[i-1][ej]:0)-(j-1>=0?prefix[ei][j-1]:0)+((i-1>=0 && j-1>=0)?prefix[i-1][j-1]:0);
                    if(sum<=threshold){
                        result=k+1;
                    }
                }
            }
        }
        return result;
    }
};