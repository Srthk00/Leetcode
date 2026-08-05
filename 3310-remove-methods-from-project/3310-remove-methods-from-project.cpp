class Solution {
public:
    vector<bool> sus;
    
    void dfs(int i,vector<vector<int>> &graph,vector<bool> &visited,int n,vector<int> &indegree){
        if(visited[i]){
            return;
        }
        sus[i]=true;
        visited[i]=true;
        for(int j:graph[i]){
            indegree[j]--;
            dfs(j,graph,visited,n,indegree);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        sus=vector<bool>(n,false);
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(auto &it:invocations){
            int u=it[0];
            int v=it[1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        vector<bool> visited(n,false);
        dfs(k,graph,visited,n,indegree);
        for(int i=0;i<n;i++){
            if(sus[i] && indegree[i]>0){
                vector<int> result(n);
                iota(result.begin(),result.end(),0);
                return result;
            }
        }
        vector<int> result;
        for(int i=0;i<n;i++){
            if(!sus[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};