class Solution {
public:
    void dfs(int src,vector<vector<int>> &graph,vector<bool> &vis){
        vis[src]=true;
        for(int it:graph[src]){
            if(!vis[it]){
                dfs(it,graph,vis);
            }
        }
    }

    int removeedges(int mid,int n,vector<vector<int>> &edges){
        vector<vector<int>> graph(n);
        for(auto &e:edges){
            int u=e[0],v=e[1],t=e[2];
            if(t>mid){
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        vector<bool> vis(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis);
                count++;
            }
        }
        return count;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        int low=0,high=0,result=-1;
        for(auto &e:edges){
            high=max(high,e[2]);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(removeedges(mid,n,edges)>=k){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
};