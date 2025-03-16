class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i:nums){
            map[i]++;
        }
        int m=*max_element(nums.begin(),nums.end());
        if(m<0){
            return 1;
        }
        for(int i=1;i<=m;i++){
            if(map.find(i)==map.end())
                return i;
        }
        return m+1;
    }
};