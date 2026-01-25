class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=k-1;
        int result=INT_MAX;
        while(j<nums.size()){
            result=min(result,nums[j++]-nums[i++]);
        }
        return result;
    }
};