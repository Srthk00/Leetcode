class Solution {
public:
    int minimumArea(vector<vector<int>>& grid,int rowup,int rowdown,int colleft,int colright) {
        int m=grid.size();
        int n=grid[0].size();
        int top=m,left=n,right=-1,bottom=-1;
        for(int i=rowup;i<rowdown;i++){
            for(int j=colleft;j<colright;j++){
                if(grid[i][j]==1){
                    top=min(top,i);
                    left=min(left,j);
                    right=max(right,j);
                    bottom=max(bottom,i);
                }
            }
        }
        return (bottom-top+1)*(right-left+1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int result=INT_MAX;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int top=minimumArea(grid,0,i,0,n);
                int left=minimumArea(grid,i,m,0,j);
                int right=minimumArea(grid,i,m,j,n);
                result=min(result,top+left+right);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int left=minimumArea(grid,0,i,0,j);
                int right=minimumArea(grid,0,i,j,n);
                int bottom=minimumArea(grid,i,m,0,n);
                result=min(result,bottom+left+right);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int top=minimumArea(grid,0,i,0,j);
                int bottom=minimumArea(grid,i,m,0,j);
                int right=minimumArea(grid,0,m,j,n);
                result=min(result,top+bottom+right);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int top=minimumArea(grid,0,i,j,n);
                int bottom=minimumArea(grid,i,m,j,n);
                int left=minimumArea(grid,0,m,0,j);
                result=min(result,top+bottom+left);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                int top=minimumArea(grid,0,i,0,n);
                int mid=minimumArea(grid,i,j,0,n);
                int bottom=minimumArea(grid,j,m,0,n);
                result=min(result,top+mid+bottom);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int left=minimumArea(grid,0,m,0,i);
                int mid=minimumArea(grid,0,m,i,j);
                int right=minimumArea(grid,0,m,j,n);
                result=min(result,left+mid+right);
            }
        }
        return result;
    }
};