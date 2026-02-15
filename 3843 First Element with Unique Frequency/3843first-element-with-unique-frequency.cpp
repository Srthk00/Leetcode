class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        unordered_map<int,int> freq;
        for(auto &[e,f]:mp){
            freq[f]++;
        }
        for(int i:nums){
            if(freq[mp[i]]==1){
                return i;
            }
        }       
        return -1;
    }
};