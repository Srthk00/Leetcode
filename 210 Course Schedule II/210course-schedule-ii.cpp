class Solution {
public:
    bool dfs(int s,vector<vector<int>> &graph,vector<int> &visited,vector<int> &recstack,vector<int> &result){
        visited[s]=1;
        recstack[s]=1;
        for(auto &u:graph[s]){
            if(!visited[u]){
                if(!dfs(u,graph,visited,recstack,result)){
                    return false;
                }
            }
            else if(recstack[u]){
                return false;
            }
        }
        recstack[s]=0;
        result.push_back(s);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v=numCourses;
        vector<vector<int>> graph(v);
        for(auto &i:prerequisites){
            graph[i[1]].push_back(i[0]);
        }
        vector<int> visited(v,0);
        vector<int> recstack(v,0);
        vector<int> result;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(!dfs(i,graph,visited,recstack,result)){
                    return {};
                }
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};