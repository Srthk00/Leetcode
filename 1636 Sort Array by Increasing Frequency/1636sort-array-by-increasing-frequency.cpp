class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i:nums){
            map[i]++;
        }
        sort(nums.begin(),nums.end(),[&map](int a,int b){
            if(map[a]<map[b]){return true;}
            else if(map[a]>map[b]){return false;}
            else{return a>b;}
        });
        return nums;
    }
};