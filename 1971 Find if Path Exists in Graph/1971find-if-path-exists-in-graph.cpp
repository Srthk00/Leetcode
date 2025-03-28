class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto &i:edges){
            int m=i[0];
            int n=i[1];
            graph[m].push_back(n);
            graph[n].push_back(m);
        }
        vector<int> visited(n+1,0);
        stack<int> st;
        st.push(source);
        visited[source]=1;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(node==destination)
                return true;
            for(auto &i:graph[node]){
                if(!visited[i]){
                    st.push(i);
                    visited[i]=1;
                }
            }
        }
        return false;
    }
};