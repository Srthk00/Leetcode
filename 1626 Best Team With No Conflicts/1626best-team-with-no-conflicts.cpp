class Solution {
public:
    int dp[1001][1001];

    int solve(int i,vector<pair<int,int>> &nums,int last){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][last+1]!=-1){
            return dp[i][last+1];
        }
        int donttake=solve(i+1,nums,last);
        int take=0;
        if(last==-1 || nums[i].second>=nums[last].second){
            take=nums[i].second+solve(i+1,nums,i);
        }

        return dp[i][last+1]=max(take,donttake);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>> players;
        for(int i=0;i<scores.size();i++){
            players.push_back({ages[i],scores[i]});
        }
        sort(players.begin(),players.end());
        return solve(0,players,-1);
    }
};