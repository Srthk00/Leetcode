class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int result=-1;
        while(i<j && nums[i]<0 && nums[j]>0){
            if(nums[j]==nums[i]*-1){
                result=max(result,nums[j]);
                i++;j--;
            }
            else if(nums[j]<nums[i]*-1){
                i++;
            }
            else{
                j--;
            }
        }
        return result;
    }
};