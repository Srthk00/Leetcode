class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        while(start<end){
            int diff=(start+end)/2;
            if(diff>0 && diff<nums.size() && nums[diff]>nums[diff+1] && nums[diff]>nums[diff-1]){
                return diff;
            }
            else if(nums[diff]<nums[diff+1]){
                start=diff+1;
            }
            else{
                end=diff-1;
            }
        }
        return start;
    }
};