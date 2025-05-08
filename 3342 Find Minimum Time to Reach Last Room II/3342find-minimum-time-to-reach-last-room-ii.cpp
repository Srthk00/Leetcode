class Solution {
public:
    typedef tuple<int,int,int,int> tiiii;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<tiiii,vector<tiiii>,greater<tiiii>> pq;
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pq.emplace(0,0,0,0);
        vector<int> dirx={0,1,0,-1};
        vector<int> diry={1,0,-1,0};
        while(!pq.empty()){
            auto [time,u,v,s]=pq.top();
            pq.pop();
            if(time > dist[u][v]) continue;
            if(u==n-1 && v==m-1){
                return time;
            }
            for(int i=0;i<4;i++){
                int nu=u+dirx[i];
                int nv=v+diry[i];
                if(nu>=0 && nu<n && nv>=0 && nv<m){
                    int wait=max(moveTime[nu][nv]-time,0);
                    int step=(s%2==0)?1:2;
                    int currtime=wait+time+step;
                    if(currtime<dist[nu][nv]){
                        dist[nu][nv]=currtime;
                        pq.emplace(currtime,nu,nv,s+1);
                    }
                }
            }
        }
        return -1;
    }
};