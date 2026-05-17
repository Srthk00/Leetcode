class Solution {
public:
    bool dfs(vector<int> &nums,vector<bool> &vis,int start){
        if(vis[start]){
            return false;
        }
        if(nums[start]==0){
            return true;
        }
        vis[start]=true;
        int left=start-nums[start];
        int right=start+nums[start];
        bool fromleft=false,fromright=false;
        if(left>=0){
            fromleft=dfs(nums,vis,left);
        }
        if(right<nums.size()){
            fromright=dfs(nums,vis,right);
        }
        return fromleft || fromright;
    }

    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> visited(n,false);
        return dfs(arr,visited,start);
    }
};