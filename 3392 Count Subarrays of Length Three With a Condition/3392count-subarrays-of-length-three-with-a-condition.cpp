class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+2;
            if(double(nums[i]+nums[j])==double(nums[i+1]/2.00)){
                count++;
            }
        }
        return count;
    }
};