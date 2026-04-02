class Solution {
public:
    int m,n;
    vector<vector<vector<int>>> dp;

    int solve(int i,int j,vector<vector<int>> &coins,int neutral){
        if(i>=m || j>=n){
            return INT_MIN;
        }
        if(dp[i][j][neutral]!=-1e9){
            return dp[i][j][neutral];
        }
        if(i==m-1 && j==n-1){
            if(coins[i][j]>=0){
                return coins[i][j];
            }
            else{
                if(neutral){
                    return 0;
                }
                return coins[i][j];
            }
        }
        int right=solve(i,j+1,coins,neutral);
        int down=solve(i+1,j,coins,neutral);
        int gain=0;
        if(coins[i][j]>=0){
            gain=coins[i][j]+max(right,down);
        }
        else{
            int rob=coins[i][j]+max(down,right);
            int notRob=INT_MIN;
            if(neutral){
                int neutralRight=solve(i,j+1,coins,neutral-1);
                int neutralDown=solve(i+1,j,coins,neutral-1);
                notRob=max(neutralRight,neutralDown);
            }
            gain=max(rob,notRob);
        }
        return dp[i][j][neutral]=gain;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m=coins.size();n=coins[0].size();
        dp=vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(3,-1e9)));
        return solve(0,0,coins,2);
    }
};