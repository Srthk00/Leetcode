class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        for(int i:nums){
            if(mp[i]==1 && i%2==0){
                return i;
            }
        }
        return -1;
    }
};