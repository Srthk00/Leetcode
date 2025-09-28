class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int peri=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]<nums[i+1]+nums[i+2]){
                peri=nums[i]+nums[i+1]+nums[i+2];
                break;
            }
        }
        return peri;
    }
};