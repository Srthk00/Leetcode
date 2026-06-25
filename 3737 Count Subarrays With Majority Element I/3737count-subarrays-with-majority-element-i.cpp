class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int result=0;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target){temp++;}
                if(2*temp>(j-i+1)){result++;}
            }
        }
        return result;
    }
};