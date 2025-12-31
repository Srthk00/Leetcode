class Solution {
public:
    int r,c;
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> grid;
    vector<vector<bool>> visited;

    bool issafe(int m,int n,int i,int j){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==1 || visited[i][j]){return false;}
        return true;
    }

    bool func(int m,int n,vector<vector<int>> &nums,int till){
        grid.assign(m,vector<int>(n,0));
        visited.assign(m,vector<bool>(n,false));
        for(int i=0;i<=till;i++){
            int x=nums[i][0]-1;
            int y=nums[i][1]-1;
            grid[x][y]=1;
        }
        // x,y of the cell and use x to check row
        queue<pair<int,int>> que;
        for(int i=0;i<n;i++){
            if(!grid[0][i]){
                que.push({0,i});
                visited[0][i]=true;
            }
        }
        while(!que.empty()){
            auto [x,y]=que.front();
            que.pop();
            if(x==m-1){return true;}
            for(auto &it:dir){
                int nx=x+it[0];
                int ny=y+it[1];
                if(issafe(m,n,nx,ny)){
                    que.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        r=row,c=col;
        int low=0,high=cells.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(func(row,col,cells,mid)){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};