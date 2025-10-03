class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        priority_queue<pp,vector<pp>,greater<>> pq;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j:{0,n-1}){
                pq.push({heightMap[i][j],{i,j}});
                visited[i][j]=true;
            }
        }
        for(int j=0;j<n;j++){
            for(int i:{0,m-1}){
                pq.push({heightMap[i][j],{i,j}});
                visited[i][j]=true;
            }
        }
        int result=0;
        while(!pq.empty()){
            pp temp=pq.top();
            pq.pop();
            int h=temp.first;
            int i=temp.second.first;
            int j=temp.second.second;
            for(auto &d:dir){
                int ni=i+d[0];
                int nj=j+d[1];
                if(ni>=0 && ni<m && nj>=0 && nj<n && !visited[ni][nj]){
                    result+=max(h-heightMap[ni][nj],0);
                    pq.push({max(h,heightMap[ni][nj]),{ni,nj}});
                    visited[ni][nj]=true;
                }
            }
        }
        return result;
    }
};