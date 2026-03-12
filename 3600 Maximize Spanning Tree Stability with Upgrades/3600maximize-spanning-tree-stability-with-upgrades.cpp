class Solution{
public:
    int find(int x,vector<int> &parent){
        if(x==parent[x]){return x;}
        return parent[x]=find(parent[x],parent);
    }

    bool Union(int x,int y,vector<int> &parent,vector<int> &rank){
        int px=find(x,parent);
        int py=find(y,parent);
        if(px==py){return false;}
        if(rank[px]>rank[py]){
            parent[py]=px;
        }
        else if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else{
            parent[px]=py;
            rank[py]++;
        }
        return true;
    }

    bool check(int n,vector<vector<int>> &edges,int k,int mid){
        vector<int> parent(n),rank(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<vector<int>> upgrade;
        for(auto&e:edges){
            int u=e[0],v=e[1],s=e[2],m=e[3];
            if(m==1){
                if(s<mid)return false;
                Union(u,v,parent,rank);
            }
            else{
                if(s>=mid){
                    Union(u,v,parent,rank);
                }
                else if(2*s>=mid){
                    upgrade.push_back({u,v});
                }
            }
        }
        for(auto &e:upgrade){
            int u=e[0],v=e[1];
            if(find(u,parent)!=find(v,parent)){
                if(k<=0)return false;
                Union(u,v,parent,rank);
                k--;
            }
        }
        int root=find(0,parent);
        for(int i=1;i<n;i++){
            if(find(i,parent)!=root){return false;}
        }
        return true;
    }

    int maxStability(int n, vector<vector<int>> &edges, int k) {
        vector<int>parent(n),rank(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
        for(auto&e:edges){
            int u=e[0],v=e[1],m=e[3];
            if(m==1){
                if(find(u,parent)==find(v,parent)){return -1;}
                Union(u,v,parent,rank);
            }
        }
        int result=-1,low=1,high=2e5;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(n,edges,k,mid)){
                result=mid;
                low=mid+1;
            }
            else{high=mid-1;}
        }
        return result;
    }
};