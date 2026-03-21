class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int top=x;top<x+k/2;top++){
            for(int i=y;i<y+k;i++){
                swap(grid[top][i],grid[x+k-1-(top-x)][i]);
            }
        }
        return grid;
    }
};