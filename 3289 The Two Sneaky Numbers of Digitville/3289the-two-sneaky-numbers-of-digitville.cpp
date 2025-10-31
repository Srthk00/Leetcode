class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> map;
        for(int i:nums){
            map[i]++;
        }
        for(auto &[n,f]:map){
            if(f==2){result.push_back(n);}
        }
        return result;
    }
};