class Solution {
public:
    vector<vector<int>> dp;
    int bs(vector<vector<int>> &nums,int low,int high,int time){
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid][0]<=time){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }

    int func(vector<vector<int>> &nums,int idx,int s){
        if(idx>=nums.size() || s==2){return 0;}
        if(dp[idx][s]!=-1){return dp[idx][s];}
        int new_idx=bs(nums,idx+1,nums.size(),nums[idx][1]);
        int take=nums[idx][2]+func(nums,new_idx,s+1);
        int donttake=func(nums,idx+1,s);
        return dp[idx][s]=max(take,donttake);
    } 

    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        dp.assign(n,vector<int>(3,-1));
        sort(events.begin(),events.end());
        return func(events,0,0);
    }
};