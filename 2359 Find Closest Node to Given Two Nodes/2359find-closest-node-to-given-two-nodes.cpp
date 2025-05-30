class Solution {
public:
    void bfs(int node,vector<vector<int>> &graph,vector<bool> &visited,vector<int> &nums){
        queue<int> que;
        que.push(node);
        nums[node]=0;
        visited[node]=true;
        int level=1;
        while(!que.empty()){
            int s=que.size();
            while(s-->0){
                int temp=que.front();
                que.pop();
                for(int v:graph[temp]){
                    if(!visited[v]){
                        visited[v]=true;
                        nums[v]=level;
                        que.push(v);
                    }
                }
            }
            level++;
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int v=edges.size();
        vector<vector<int>> graph(v);
        for(int i=0;i<v;i++){
            if(edges[i]!=-1){
                graph[i].push_back(edges[i]);
            }
        }
        vector<bool> visited(v,false);
        vector<int> bfs1(v,-1);
        vector<int> bfs2(v,-1);
        bfs(node1,graph,visited,bfs1);
        fill(visited.begin(),visited.end(),false);
        bfs(node2,graph,visited,bfs2);
        int mindist=INT_MAX;
        int result=-1;
        for(int i=0;i<v;i++){
            if(bfs1[i]!=-1 && bfs2[i]!=-1){
                int dist=max(bfs1[i],bfs2[i]);
                if(dist<mindist){
                    mindist=dist;
                    result=i;
                }
            }
        }
        return result;
    }
};