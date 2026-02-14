class Solution {
public:
    vector<vector<double>> dp;

    double func(int poured,int i,int j){
        if(i<0 || j<0 || i<j){return 0.0;}
        if(i==0 && j==0){return poured;}
        if(dp[i][j]!=-1){return dp[i][j];}
        double up_left=(func(poured,i-1,j-1)-1)/2.0;
        double up_right=(func(poured,i-1,j)-1)/2.0;
        if(up_left<0){up_left=0.0;}
        if(up_right<0){up_right=0.0;}
        return dp[i][j]=up_left+up_right;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        dp.assign(101,vector<double>(101,-1));
        return min(1.0,func(poured,query_row,query_glass));
    }
};