class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        vector<vector<int>> res;
        for(auto &it:mp){
            res.push_back({it.first,it.second});
        }
        sort(res.begin(),res.end());
        for(int i=0;i<res.size();i++){
            for(int j=i+1;j<res.size();j++){
                if(res[i][1]!=res[j][1]){return {res[i][0],res[j][0]};}
            }
        }
        return {-1,-1};
    }
};