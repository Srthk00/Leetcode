class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> result(n,1);
        for(int i=0;i<n;i++){
            int j=i;
            while(j<n-1 && j<i+k-1){
                if(nums[j]<nums[j+1]){
                    result[i]++;
                }
                j++;
            }
        }
        for(int i=0;i<n-k;i++){
            if(result[i]>=k && result[i+k]>=k){return true;}
        }
        return false;
    }
};