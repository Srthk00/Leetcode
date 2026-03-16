class Solution {
public:
    int m,n;
    vector<vector<int>> g;

    int rombus(int x,int y,int l){
        int sum=0;
        int i=x,j=y;
        // top -> right
        for(int k=0;k<l;k++){
            sum+=g[i+k][j+k];
        }
        // right -> bottom
        for(int k=0;k<l;k++){
            sum+=g[i+l+k][j+l-k];
        }
        // bottom -> left
        for(int k=0;k<l;k++){
            sum+=g[i+2*l-k][j-k];
        }
        // left -> top
        for(int k=0;k<l;k++){
            sum+=g[i+l-k][j-l+k];
        }
        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        g=grid;
        int max_l=min(m,n)/2;
        priority_queue<int> pq;
        set<int> used;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!used.count(grid[i][j])){
                    pq.push(grid[i][j]);
                    used.insert(grid[i][j]);
                }
                for(int l=1;l<=max_l;l++){
                    if(j-l<0 || j+l>=n || i+2*l>=m){break;}
                    int val=rombus(i,j,l);
                    if(!used.count(val)){
                        pq.push(val);
                        used.insert(val);
                    }
                }
            }
        }
        vector<int> result;
        for(int i=0;i<3 && !pq.empty();i++){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};