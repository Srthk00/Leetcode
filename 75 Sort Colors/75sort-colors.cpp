class Solution {
public:
    void sortColors(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end());
        vector<int> freq(m+1,0);
        for(int i:nums){
            freq[i]++;
        }
        for(int i=1;i<freq.size();i++){
            freq[i]=freq[i]+freq[i-1];
        }
        vector<int> temp(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            temp[freq[nums[i]]-1]=nums[i];
            freq[nums[i]]--;
        }
        nums=temp;
    }
};