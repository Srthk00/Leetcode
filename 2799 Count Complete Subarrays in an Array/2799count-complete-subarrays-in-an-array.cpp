class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        int low=0,high=0;
        unordered_map<int,int> freq;
        int count=0;
        while(high<nums.size()){
            freq[nums[high]]++;{
                while(freq.size()==set.size()){
                    count+=nums.size()-high;
                    freq[nums[low]]--;
                    if(freq[nums[low]]==0){
                        freq.erase(nums[low]);
                    }
                    low++;
                }
            }
            high++;
        }
        return count;
    }
};