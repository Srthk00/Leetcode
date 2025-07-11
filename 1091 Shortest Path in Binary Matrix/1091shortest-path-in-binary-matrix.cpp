class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1){return -1;}
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({1,{0,0}});
        auto check=[&](int i,int j){
            if(i<0 || j<0 || i>=n || j>=n){return false;}
            return true;
        };
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        while(!pq.empty()){
            int cost=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            for(auto &d:dir){
                int ni=i+d[0];
                int nj=j+d[1];
                if(check(ni,nj)){
                    if(grid[ni][nj]==0){
                        if(dist[ni][nj]>cost+1){
                            dist[ni][nj]=cost+1;
                            pq.push({dist[ni][nj],{ni,nj}});
                        }
                    }
                }
            }
        }
        return dist[n-1][n-1]==1e9?-1:dist[n-1][n-1];
    }
};