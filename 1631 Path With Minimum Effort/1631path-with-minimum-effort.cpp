class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        auto check=[&m,&n](int i,int j){
            if(i<0 || j<0 || i>=m || j>=n){return false;}
            return true;
        };
        while(!pq.empty()){
            int d=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            for(auto &it:dir){
                int ni=i+it[0];
                int nj=j+it[1];
                if(check(ni,nj)){
                    int diff=abs(heights[i][j]-heights[ni][nj]);
                    int new_dist=max(d,diff);
                    if(dist[ni][nj]>new_dist){
                        dist[ni][nj]=new_dist;
                        pq.push({new_dist,{ni,nj}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};