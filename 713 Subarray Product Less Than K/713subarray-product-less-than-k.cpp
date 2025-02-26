class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int left,right;
        for(int i=0;i<nums.size();i++){
            left=right=i;
            int prod=1;
            while(right<nums.size() && prod*nums[right]<k){
                prod*=nums[right];
                right++;
            }
            count+=right-left;
        }
        return count;
    }
};