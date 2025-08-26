class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxdiag=0.00;
        int maxarea=0;
        for(auto &it:dimensions){
            double currdiag=(double)sqrt((it[0]*it[0])+(it[1]*it[1]));
            int currarea=it[0]*it[1];
            if(currdiag>maxdiag){
                maxdiag=currdiag;
                maxarea=currarea;
            }
            if(currdiag==maxdiag){
                maxarea=max(maxarea,currarea);
            }
        }
        return maxarea;
    }
};