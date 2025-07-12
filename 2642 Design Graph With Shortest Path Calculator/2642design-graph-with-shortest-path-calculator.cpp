class Graph {
public:
    typedef pair<int,int> pii;
    int n;
    vector<vector<pair<int,int>>> graph;
    Graph(int n, vector<vector<int>>& edges) {
        this->n=n;
        graph=vector<vector<pair<int,int>>>(n);
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            graph[u].push_back({v,w});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(n,1e9);
        dist[node1]=0;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,node1});
        while(!pq.empty()){
            int w=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &ne:graph[node]){
                if(dist[ne.first]>ne.second+dist[node]){
                    dist[ne.first]=ne.second+dist[node];
                    pq.push({dist[ne.first],ne.first});
                }
            }
        }
        return dist[node2]==1e9?-1:dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */