class Solution {
public:
    vector<vector<int>> g;

    int func(int x,int y,int k){
        vector<int> temp;
        for(int i=x;i<x+k;i++){
            for(int j=y;j<y+k;j++){
                temp.push_back(g[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        if(temp[0]==temp[temp.size()-1]){return 0;}
        int result=INT_MAX;
        for(int i=0;i<temp.size()-1;i++){
            if(abs(temp[i]-temp[i+1])==0){continue;}
            result=min(result,abs(temp[i]-temp[i+1]));
        }
        return result;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        g=grid;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> result(m-k+1,vector<int>(n-k+1,0));
        for(int i=0;i+k-1<m;i++){
            for(int j=0;j+k-1<n;j++){
                result[i][j]=func(i,j,k);
            }
        }
        return result;
    }
};