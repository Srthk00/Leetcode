class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i,int j,vector<int> &nums){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take_left=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int take_right=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        return dp[i][j]=max(take_left,take_right);
    }

    bool stoneGame(vector<int>& piles) {
        int sum=accumulate(piles.begin(),piles.end(),0);
        dp=vector<vector<int>>(piles.size(),vector<int>(piles.size(),-1));
        return (solve(0,piles.size()-1,piles)*2)>sum;
    }
};