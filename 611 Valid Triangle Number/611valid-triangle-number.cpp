class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int result=0;
        for(int i=nums.size()-1;i>=2;i--){
            int low=0,high=i-1;
            while(low<high){
                if(nums[low]+nums[high]>nums[i]){
                    result+=(high-low);
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        return result;
    }
};