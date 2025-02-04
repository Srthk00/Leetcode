class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int point=nums[0],curr=nums[0],max=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>point){
                curr+=nums[i];
                point=nums[i];
                if(curr>max){
                    max=curr;
                }
            }
            else{
                curr=nums[i];
                point=nums[i];
            }
        }
        return max;
    }
};