class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0){return false;}
        int splitssize=n/k;
        unordered_map<int,int> map;
        for(int i:nums){
            map[i]++;
        }
        for(auto &[i,f]:map){
            if(f>splitssize){return false;}
        }
        return true;
    }
};