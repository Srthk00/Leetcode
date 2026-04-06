class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int,unordered_set<int>> xmp,ymp;
        for(auto &it:obstacles){
            xmp[it[0]].insert(it[1]);
            ymp[it[1]].insert(it[0]);
        }
        // int squaredDistance = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        int d=0;
        int x=0,y=0;
        int result=0;
        for(int i:commands){
            if(i==-1){
                d=(d+1)%4;
            }
            else if(i==-2){
                d=(d+3)%4;
            }
            else{
                for(int a=0;a<i;a++){
                    int x_=x,y_=y;
                    if(d==0){
                        y_++;
                    }
                    else if(d==1){
                        x_++;
                    }
                    else if(d==2){
                        y_--;
                    }
                    else{
                        x_--;
                    }
                    if(xmp.count(x_) && xmp[x_].count(y_)){
                        break;
                    }
                    x=x_;y=y_;
                }
                result=max(result,(x-0)*(x-0)+(y-0)*(y-0));
            }
        }
        return result;
    }
};