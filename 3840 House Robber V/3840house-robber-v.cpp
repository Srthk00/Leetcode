class Solution {
public:
    vector<long long> dp;
    
    long long func(int i,vector<int> &nums,vector<int>& color){
        if(i>=nums.size()){return 0;}
        if(dp[i]!=-1){return dp[i];}
        //not take
        long long nottake=func(i+1,nums,color);
        // take
        long long take=0;
        if(i<nums.size()-1 && color[i]!=color[i+1]){
             take=nums[i]+func(i+1,nums,color);   
        }
        // if next house is same color, we cannot take from next house, so just move to the house after that
        // case of not robbing the current house is covered by last case
        else{
            take=nums[i]+func(i+2,nums,color);
        }
        return dp[i]=max(take,nottake);
    }
    
    long long rob(vector<int>& nums, vector<int>& colors) {
        dp.assign(nums.size(),-1);
        return func(0,nums,colors); 
    }
};