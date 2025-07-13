class Solution {
public:
    int find(vector<int> &parent,int x){
        if(parent[x]!=x){
            parent[x]=find(parent,parent[x]);
        }
        return parent[x];
    }

    bool UNION(vector<int> &parent,vector<int> &SIZE,int x,int y){
        int repx=find(parent,x);
        int repy=find(parent,y);
        if(repx==repy){return false;}
        if(SIZE[repx]<SIZE[repy]){
            parent[repx]=repy;
            SIZE[repy]+=SIZE[repx];
        }
        else{
            parent[repy]=repx;
            SIZE[repx]+=SIZE[repy];
        }
        return true;
    }
    
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(),[](vector<int> &a,vector<int> &b){
           return a[2]<b[2]; 
        });
        vector<int> parent(n);
        for(int i=0;i<n;i++){parent[i]=i;}
        vector<int> SIZE(n,1);
        vector<int> minedges;
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            if(UNION(parent,SIZE,u,v)){
                minedges.push_back(w);
            }
        }
        sort(minedges.begin(),minedges.end());
        int m=minedges.size();
        if(m<k){return 0;}
        return minedges[m-k];
    }
};