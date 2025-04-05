class Solution {
public:
    void rotten(vector<vector<int>> &grid,queue<pair<int,int>> &que,int i,int j,int *fresh){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || grid[i][j]==2){
            return;
        }
        que.push({i,j});
        grid[i][j]=2;
        (*fresh)--;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        int row=grid.size();
        int col=grid[0].size();
        int fresh=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0)
            return 0;
        int minute=0;
        while(!que.empty()){
            int size=que.size();
            minute++;
            while(size>0){
                pair<int,int> curr=que.front();
                que.pop();
                rotten(grid,que,curr.first+1,curr.second,&fresh);
                rotten(grid,que,curr.first-1,curr.second,&fresh);
                rotten(grid,que,curr.first,curr.second+1,&fresh);
                rotten(grid,que,curr.first,curr.second-1,&fresh);
                size--;
            }
        }
        return fresh==0?minute-1:-1;
    }
};