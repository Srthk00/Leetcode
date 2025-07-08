class Solution {
public:
    void buildgraph(vector<vector<pair<int,int>>> &graph,vector<vector<int>> &flights){
        for(auto &it:flights){
            int u=it[0],v=it[1],w=it[2];
            graph[u].push_back({v,w});
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        buildgraph(graph,flights);
        vector<int> dist(n,1e9);
        queue<vector<int>> que;
        que.push({0,src,0});
        while(!que.empty()){
            int s=que.front()[0];
            int node=que.front()[1];
            int tillweight=que.front()[2];
            que.pop();
            if(s>k){continue;}
            for(auto &[v,w]:graph[node]){
                if(dist[v]>w+tillweight){
                    dist[v]=w+tillweight;
                    que.push({s+1,v,dist[v]});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};