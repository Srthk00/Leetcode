class Solution {
public:
    void dfs(int i,vector<vector<int>> &graph,vector<bool> &visited){
        if(visited[i]){
            return;
        }
        visited[i]=true;
        for(auto &it:graph[i]){
            dfs(it,graph,visited);
        }
    }

    void DFS(int idx,int i,vector<vector<int>> &graph,vector<bool> &visited,vector<pair<int,int>> &comp){
        if(visited[i]){
            return;
        }
        visited[i]=true;
        comp[idx].first++;
        comp[idx].second+=graph[i].size();
        for(auto &it:graph[i]){
            DFS(idx,it,graph,visited,comp);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto &it:edges){
            int s=it[0];
            int d=it[1];
            graph[s].push_back(d);
            graph[d].push_back(s);
        }
        int result=0;
        vector<bool> visited(n,false);
        vector<int> temp;
        vector<pair<int,int>> comp;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                temp.push_back(i);
                dfs(i,graph,visited);
            }
        }
        for(int i=0;i<temp.size();i++){
            comp.push_back({0,0});
        }
        fill(visited.begin(),visited.end(),false);
        for(int i=0;i<temp.size();i++){
            DFS(i,temp[i],graph,visited,comp);
        }
        for(int i=0;i<comp.size();i++){
            comp[i].second/=2;
            int m=comp[i].first;
            int n=comp[i].second;
            if((m*(m-1)/2)==n){
                result++;
            }
        }
        return result;
    }
};