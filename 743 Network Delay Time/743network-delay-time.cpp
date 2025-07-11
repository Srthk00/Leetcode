class Solution {
public:
    typedef pair<int,int> P;
    void buildgraph(vector<vector<int>> &edges,vector<vector<pair<int,int>>> &graph,int n){
        for(auto &e:edges){
            int s=e[0],d=e[1],w=e[2];
            graph[s].push_back({d,w});
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        buildgraph(times,graph,n);
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int w=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(w>dist[u]){continue;}
            for(auto &it:graph[u]){
                int v=it.first;
                int wt=it.second;
                if(dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        int result=*max_element(dist.begin()+1,dist.end());
        return result==1e9?-1:result;
    }
};