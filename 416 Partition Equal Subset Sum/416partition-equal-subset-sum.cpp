class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1){return false;}
        int half=sum/2;
        vector<vector<bool>> dp(n,vector<bool>(half+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=half){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=half;j++){
                bool take=false;
                if(j>=nums[i]){
                    take=dp[i-1][j-nums[i]];
                }
                bool donttake=dp[i-1][j];
                dp[i][j]=take||donttake;
            }
        }
        return dp[n-1][half];
    }
};