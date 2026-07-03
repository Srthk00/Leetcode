class Solution {
public:
    bool check(int n,vector<vector<pair<int,int>>> &G,vector<bool> &online,long long k,int mid){
        vector<long long> dist(n,LLONG_MAX);
        vector<int> indegree(n,0);
        vector<vector<pair<int,int>>> graph(n);
        for(int node=0;node<n;node++){
            for(auto &[v,c]:G[node]){
                if(c>=mid && (v==n-1 || online[v])){
                    graph[node].push_back({v,c});
                    indegree[v]++;
                }
            }
        }
        queue<int> que;
        dist[0]=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(auto &[v,c]:graph[u]){
                if(dist[u]!=LLONG_MAX && dist[v]>dist[u]+c){
                    dist[v]=dist[u]+c;
                }
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                }
            }
        }
        if(dist[n-1]<=k){
            return true;
        }
        return false;
    }
    
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        int low=INT_MAX,high=INT_MIN;
        vector<vector<pair<int,int>>> graph(n);
        int result=-1;
        for(auto &it:edges){
            int u=it[0],v=it[1],c=it[2];
            graph[u].push_back({v,c});
            low=min(low,c);
            high=max(high,c);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(n,graph,online,k,mid)){
                result=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return result;
    }
};