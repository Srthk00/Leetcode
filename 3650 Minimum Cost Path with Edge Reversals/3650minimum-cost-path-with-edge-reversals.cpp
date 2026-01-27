class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        int s=edges.size();
        for(int i=0;i<s;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            edges.push_back({v,u,2*w});
        }
        s=edges.size();
        vector<vector<pair<int,int>>> graph(n);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            graph[u].push_back({v,w});
        }
        // weight, dest
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> result(n,1e9);
        result[0]=0;
        pq.push({result[0],0});
        while(!pq.empty()){
            auto [w,src]=pq.top();
            pq.pop();
            if(w>result[src]){continue;}
            for(auto &it:graph[src]){
                int v=it.first;
                int w_=it.second;
                if(result[v]>w_+result[src]){
                    result[v]=w_+result[src];
                    pq.push({result[v],v});
                }
            }
        }
        return result[n-1]==1e9?-1:result[n-1];
    }
};