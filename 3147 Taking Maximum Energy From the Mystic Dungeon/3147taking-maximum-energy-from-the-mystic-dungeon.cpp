class Solution {
public:
    vector<int> dp;
    int x;
    int func(int i,vector<int> &nums){
        if(i>=nums.size()){return 0;}
        if(dp[i]!=-1){return dp[i];}
        return dp[i]=nums[i]+func(i+x,nums);
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int result=INT_MIN;
        x=k;
        dp=vector<int>(energy.size(),-1);
        for(int i=0;i<energy.size();i++){
            result=max(result,func(i,energy));
        }
        return result;
    }
};