class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=-(n-1);i<n;i++){
            int row,col;
            if(i<=0){
                row=i*(-1);
                col=0;
            }
            else{
                row=0;
                col=i;
            }
            vector<int> currdiag;
            int x=row,y=col;
            while(x>=0 && y>=0 && x<n && y<n){
                currdiag.push_back(grid[x++][y++]);
            }
            if(i<=0){
                sort(currdiag.rbegin(),currdiag.rend());
            }
            else{
                sort(currdiag.begin(),currdiag.end());
            }
            x=row;y=col;
            int a=0;
            while(a<currdiag.size()){
                grid[x++][y++]=currdiag[a++];
            }
        }
        return grid;
    }
};