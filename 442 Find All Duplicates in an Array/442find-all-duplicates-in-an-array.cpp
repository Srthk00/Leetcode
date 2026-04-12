class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> map;
        for(int i:nums){
            map[i]++;
        }
        for(auto &i:map){
            if(i.second>1){
                result.push_back(i.first);
            }
        }
        return result;
    }
};