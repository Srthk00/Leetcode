class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int steps=nums.size();
        while(steps-->0){
            for(int i=0;i<steps;i++){
                if(i!=steps){
                    nums[i]=(nums[i]+nums[i+1])%10;
                }
            }
        }
        return nums[0];
    }
};