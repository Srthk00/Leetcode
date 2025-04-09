class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i:nums){
            map[i]++;
        }
        if(*min_element(nums.begin(),nums.end())<k){
            return -1;
        }
        int count=0;
        for(auto &i:map){
            if(i.first>k)
                count++;
        }
        return count;
    }
};