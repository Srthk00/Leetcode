class Solution {
public:
    void dfs(int s,vector<vector<int>> &graph,vector<int> &visited){
        visited[s]=1;
        for(auto &i:graph[s]){
            if(!visited[i]){
                dfs(i,graph,visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<vector<int>> graph(n);
        for(auto &i:connections){
            int a=i[0];
            int b=i[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int count=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,graph,visited);
            }
        }
        return count-1;
    }
};