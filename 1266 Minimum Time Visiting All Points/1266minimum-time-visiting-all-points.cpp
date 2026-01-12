class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result=0;
        for(int i=0;i<points.size()-1;i++){
            int x=points[i][0],y=points[i][1];
            int nx=points[i+1][0],ny=points[i+1][1];
            int diffx=abs(x-nx),diffy=abs(y-ny);
            result+=(min(diffx,diffy)+abs(diffx-diffy));
        }
        return result;
    }
};