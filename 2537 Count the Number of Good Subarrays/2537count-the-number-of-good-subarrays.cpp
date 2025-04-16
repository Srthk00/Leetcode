class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int low=0,high=0,pairs=0;
        long long count=0;
        while(high<nums.size()){
            freq[nums[high]]++;
            if(freq[nums[high]]>=2){
                pairs+=freq[nums[high]]-1;
            }
            while(pairs>=k){
                count+=nums.size()-high;
                pairs-=freq[nums[low]]-1;
                freq[nums[low]]--;
                low++;
            }
            high++;
        }
        return count;
    }
};