class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()<=2){return nums.size();}
        int result=2,curr=2;
        for(int i=2;i<nums.size();i++){
            if(nums[i-1]+nums[i-2]==nums[i]){curr++;}
            else{result=max(result,curr);curr=2;}
        }
        result=max(result,curr);
        return result;
    }
};