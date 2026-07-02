class Solution {
public:
    typedef pair<int,pair<int,int>> piii;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dist(m+1,vector<int>(n+1,1e9));
        dist[0][0]=grid[0][0];
        deque<piii> dq;
        dq.push_front({grid[0][0],{0,0}});
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        auto check=[&](int i,int j){
            if(i<0 || j<0 || i>=m || j>=n){
                return false;
            }
            return true;
        };
        while(!dq.empty()){
            int cost=dq.front().first;
            int i=dq.front().second.first;
            int j=dq.front().second.second;
            dq.pop_front();
            for(auto &it:dir){
                int ni=i+it[0];
                int nj=j+it[1];
                if(check(ni,nj)){
                    if(dist[ni][nj]>cost+grid[ni][nj]){
                        dist[ni][nj]=cost+grid[ni][nj];
                        if(!grid[ni][nj]){
                            dq.push_front({dist[ni][nj],{ni,nj}});
                        }
                        else{
                            dq.push_back({dist[ni][nj],{ni,nj}});
                        }
                    }
                }
            }
        }
        return dist[m-1][n-1]>=health?false:true;
    }
};