class Solution {
public:
    int result=1e9;

    void dfs(int i,vector<vector<pair<int,int>>> &graph,vector<int> &visited){
        visited[i]=true;
        for(auto &it:graph[i]){
            result=min(it.second,result);
            if(!visited[it.first]){
                dfs(it.first,graph,visited);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto &it:roads){;
            int s=it[0];
            int d=it[1];
            int c=it[2];
            graph[s].push_back({d,c});
            graph[d].push_back({s,c});
        }
        vector<int> visited(n+1,false);
        dfs(1,graph,visited);
        return result;
    }
};