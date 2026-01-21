class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& left, vector<vector<int>>& right) {
        long long result=0;
        int n=left.size();
        for(int i=0;i<n;i++){
            int x=left[i][0],y=left[i][1];
            int X=right[i][0],Y=right[i][1];
            for(int j=0;j<n;j++){
                if(i==j){continue;}
                int cx=left[j][0],cy=left[j][1];
                int cX=right[j][0],cY=right[j][1];
                if(cX<=x || cY<=y || cx>=X || cy>=Y){continue;}
                int currw=min(X,cX)-max(cx,x);
                int currh=min(Y,cY)-max(cy,y);
                int side=min(currh,currw);
                result=max(result,1LL*side*side);
            }
        }
        return result;
    }
};