class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> suffix(n,0);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],nums[i]);
        }
        int num=nums[0];
        int result=0,instable=-(1e9+1);
        for(int i=0;i<n;i++){
            num=max(num,nums[i]);
            if(num-suffix[i]<=k){
                return i;
            }
        }
        return -1;
    }
};