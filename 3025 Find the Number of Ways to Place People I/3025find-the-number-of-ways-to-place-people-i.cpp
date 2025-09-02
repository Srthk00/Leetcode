class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int result=0;
        for(int first=0;first<points.size();first++){
            int x1=points[first][0],y1=points[first][1];
            for(int second=first+1;second<points.size();second++){
                int x2=points[second][0],y2=points[second][1];
                if(x1<x2 && y1<y2){continue;}
                bool flag=true;
                for(auto &check:points){
                    int x=check[0],y=check[1];
                    if((x1==x && y1==y) || (x2==x && y2==y)){continue;}
                    if(x1==x2 && y1<y2){
                        if(x==x1 && (y1<=y && y<=y2)){
                            flag=false;
                            break;
                        }
                    }
                    else if((x1<=x && x<=x2) && (y2<=y && y<=y1)){
                        flag=false;
                        break;
                    }
                }
                if(flag){result++;}
            }
        }
        return result;
    }
};