class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> maxtilli(n),minafteri(n);
        maxtilli[0]=nums[0];
        minafteri[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            maxtilli[i]=max(nums[i],maxtilli[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            minafteri[i]=min(nums[i],minafteri[i+1]);
        }
        int stable=INT_MAX;
        for(int i=0;i<n;i++){
            int diff=maxtilli[i]-minafteri[i];
            if(diff<=k && stable>diff){
                return i;
            }
        }
        return -1;
    }
};