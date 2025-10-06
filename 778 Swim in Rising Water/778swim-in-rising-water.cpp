class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

    bool issafe(int i,int j,int n){
        if(i<0 || j<0 || i>=n || j>=n){return false;}
        return true;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int t=0;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({grid[0][0],{0,0}});
        visited[0][0]=true;
        while(!pq.empty()){
            pp temp=pq.top();
            pq.pop();
            int el=temp.first;
            int i=temp.second.first;
            int j=temp.second.second;
            if(el>t){t=el;}
            if(i==n-1 && j==n-1){return t;}
            for(auto &d:dir){
                int ni=i+d[0];
                int nj=j+d[1];
                if(issafe(ni,nj,n) && !visited[ni][nj]){
                    visited[ni][nj]=true;
                    pq.push({grid[ni][nj],{ni,nj}});
                }
            }
        }
        return -1;
    }
};