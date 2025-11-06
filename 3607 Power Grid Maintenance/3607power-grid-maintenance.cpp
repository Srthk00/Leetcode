class Solution {
public:
    int find(int x,vector<int> &parent){
        if(x!=parent[x]){parent[x]=find(parent[x],parent);}
        return parent[x];
    }

    void UNION(int a,int b,vector<int> &parent,vector<int> &SIZE){
        int repx=find(a,parent);
        int repy=find(b,parent);
        if(repx==repy){
            return;
        }
        else if(SIZE[repx]<SIZE[repy]){
            parent[repx]=repy;
            SIZE[repy]+=SIZE[repx];
        }
        else{
            parent[repy]=repx;
            SIZE[repx]+=SIZE[repy];
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> result;
        vector<bool> working(c+1,true);
        vector<int> parent(c+1);
        for(int i=0;i<c+1;i++){
            parent[i]=i;
        }
        vector<int> SIZE(c+1,1);
        for(auto &it:connections){
            int u=it[0];
            int v=it[1];
            UNION(u,v,parent,SIZE);
        }
        unordered_map<int,set<int>> map;
        for(int i=1;i<=c;i++){
            int root=find(i,parent);
            map[root].insert(i);
        }
        for(auto &q:queries){
            int u=q[0];
            int v=q[1];
            if(u==1){
                if(working[v]){result.push_back(v);}
                else{
                    int root=find(v,parent);
                    if(!map[root].empty()){
                        result.push_back(*map[root].begin());
                    }
                    else{
                        result.push_back(-1);
                    }
                }
            }
            else{
                working[v]=false;
                int root=find(v,parent);
                map[root].erase(v);
            }
        }
        return result;
    }
};