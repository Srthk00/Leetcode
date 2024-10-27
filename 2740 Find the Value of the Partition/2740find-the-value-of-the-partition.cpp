class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int result=nums[n-1];
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<result)
                result=nums[i]-nums[i-1];
        }
        return result;
    }
};