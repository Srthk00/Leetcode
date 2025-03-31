class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> result;
        for(int i:nums){
            map[i]++;
        }
        int s=nums.size()/3;
        for(auto &i:map){
            if(i.second>s){
                result.push_back(i.first);
            }
        }
        return result;
    }
};