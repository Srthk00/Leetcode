class Solution {
private:
public:
    int find(vector<int> &parent,int x){
        if(parent[x]!=x){
            return find(parent,parent[x]);
        }
        return parent[x];
    }

    bool UNION(vector<int> &parent,vector<int> &SIZE,int a,int b){
        int repa=find(parent,a);
        int repb=find(parent,b);
        if(repa==repb){
            return false;
        }
        if(SIZE[repa]<SIZE[repb]){
            parent[repa]=repb;
            SIZE[repb]+=SIZE[repa];
        }
        else{
            parent[repb]=repa;
            SIZE[repa]+=SIZE[repb];
        }
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> parent(n);
        vector<int> SIZE(n,1);
        for(int i=0;i<n;i++){parent[i]=i;}
        // wt, src, dest
        vector<vector<int>> edges;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dis,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        int mst=0;
        for(auto &e:edges){
            int wt=e[0],s=e[1],d=e[2];
            if(UNION(parent,SIZE,s,d)){
                mst+=wt;
            }
        }
        return mst;
    }
};