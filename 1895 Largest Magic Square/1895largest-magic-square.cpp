class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> rowprefix(m,vector<int>(n)),colprefix(m,vector<int>(n));
        for(int i=0;i<m;i++){
            rowprefix[i][0]=grid[i][0];
            for(int j=1;j<n;j++){
                rowprefix[i][j]=grid[i][j]+rowprefix[i][j-1];
            }
        }
        for(int i=0;i<n;i++){
            colprefix[0][i]=grid[0][i];
            for(int j=1;j<m;j++){
                colprefix[j][i]=grid[j][i]+colprefix[j-1][i];
            }
        }
        int result=1;
        for(int i=2;i<=min(m,n);i++){
            for(int x=0;x<=m-i;x++){
                for(int y=0;y<=n-i;y++){
                    bool ismagic=true;
                    int firstsum=rowprefix[x][y+i-1]-(y==0?0:rowprefix[x][y-1]);
                    for(int temp=x+1;temp<x+i;temp++){
                        if((rowprefix[temp][y+i-1]-(y==0?0:rowprefix[temp][y-1]))!=firstsum){
                            ismagic=false;break;
                        }
                    }
                    for(int temp=y;temp<y+i;temp++){
                        if((colprefix[x+i-1][temp]-(x==0?0:colprefix[x-1][temp]))!=firstsum){
                            ismagic=false;break;
                        }
                    }
                    int diag=0;
                    int tempi=x,tempj=y,count=i;
                    while(count-->0){
                        diag+=grid[tempi++][tempj++];
                    }
                    if(diag!=firstsum){
                        ismagic=false;
                    }
                    count=i;tempi=x+i-1;tempj=y;diag=0;
                    while(count-->0){
                        diag+=grid[tempi--][tempj++];
                    }
                    if(diag!=firstsum){
                        ismagic=false;
                    }
                    if(ismagic){
                        result=max(result,i);
                    }
                }
            }
        }
        return result;
    }
};