class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<pair<int,bool>>> g(m+1,vector<pair<int,bool>>(n+1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='X'){g[i][j].first=1;g[i][j].second=true;}
                else if(grid[i][j]=='Y'){g[i][j].first=-1;g[i][j].second=false;}
                else{g[i][j].first=0;g[i][j].second=false;}
            }
        }
        int result=0;
        for(int j=1;j<n;j++){
            g[0][j].first+=g[0][j-1].first;
            g[0][j].second=g[0][j].second || g[0][j-1].second;
            if(g[0][j].first==0 && g[0][j].second){result++;}
        }
        for(int i=1;i<m;i++){
            g[i][0].first+=g[i-1][0].first;
            g[i][0].second=g[i][0].second || g[i-1][0].second;
            if(g[i][0].first==0 && g[i][0].second){result++;}
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                g[i][j].first+=(g[i-1][j].first+g[i][j-1].first-g[i-1][j-1].first);
                g[i][j].second=g[i][j].second || g[i-1][j].second || g[i][j-1].second || g[i-1][j-1].second;
                if(g[i][j].first==0 && g[i][j].second){result++;}
            }
        }
        return result;
    }
};