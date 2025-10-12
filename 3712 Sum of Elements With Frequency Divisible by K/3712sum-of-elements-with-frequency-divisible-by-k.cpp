class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int result=0;
        for(int i:nums){mp[i]++;}
        for(auto [i,f]:mp){
            if(f%k==0){
                result+=(i*f);
            }
        }
        return result;
    }
};