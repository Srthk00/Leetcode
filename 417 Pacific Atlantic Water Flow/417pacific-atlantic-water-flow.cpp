class Solution {
public:
    bool issafe(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n){return false;}
        return true;
    }

    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(int i,int j,vector<vector<int>> &nums,vector<vector<int>> &marker,vector<vector<bool>> &visited,int m,int n){
        if(!issafe(i,j,m,n) || visited[i][j]){return;}
        marker[i][j]++;
        visited[i][j]=true;
        for(auto &d:dir){
            int ni=i+d[0];
            int nj=j+d[1];
            if(issafe(ni,nj,m,n) && nums[ni][nj]>=nums[i][j]){
                dfs(ni,nj,nums,marker,visited,m,n);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> marker(m,vector<int>(n,0));
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        // for pacific ocean
        for(int i=0;i<m;i++){
            dfs(i,0,heights,marker,visited,m,n);
        }
        for(int i=0;i<n;i++){
            dfs(0,i,heights,marker,visited,m,n);
        }
        visited.assign(visited.size(),vector<bool>(visited[0].size(),false));
        // for atlantic ocean
        for(int i=0;i<m;i++){
            dfs(i,n-1,heights,marker,visited,m,n);
        }
        for(int i=0;i<n;i++){
            dfs(m-1,i,heights,marker,visited,m,n);
        }
        vector<vector<int>> result;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(marker[i][j]==2){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};