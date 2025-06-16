class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maximum=-1;
        int small=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[small]){
                small=i;
            }
            else{
                maximum=max(maximum,nums[i]-nums[small]);
            }
        }
        return maximum;
    }
};