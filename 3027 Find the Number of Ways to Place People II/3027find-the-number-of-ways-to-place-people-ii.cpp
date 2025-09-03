class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int result=0;
        for(int first=0;first<points.size();first++){
            int x1=points[first][0],y1=points[first][1];
            int maxy=INT_MIN;
            for(int second=first+1;second<points.size();second++){
                int x2=points[second][0],y2=points[second][1];
                if(x1<x2 && y1<y2){continue;}
                if(maxy<y2){
                    result++;
                    maxy=y2;
                }
            }
        }
        return result;
    }
};