class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> rightmax(nums.size(),0);
        rightmax[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],nums[i+1]);
        }
        long long maxsum=0;
        int maxvalue=nums[0];
        for(int i=1;i<nums.size()-1;i++){
            long long currsum=(long long)(maxvalue-nums[i])*rightmax[i];
            maxsum=max(maxsum,currsum);
            maxvalue=max(maxvalue,nums[i]);
        }
        return maxsum;
    }
};