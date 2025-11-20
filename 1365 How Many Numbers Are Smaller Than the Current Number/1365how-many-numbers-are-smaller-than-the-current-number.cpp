class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int i:nums){
            freq[i]++;
        }
        for(int i=1;i<101;i++){
            freq[i]=freq[i-1]+freq[i];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){continue;}
            nums[i]=freq[nums[i]-1];
        }
        return nums;
    }
};