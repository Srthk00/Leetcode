class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0]+nums[1]<=nums[2] || nums[0]+nums[2]<=nums[1] || nums[1]+nums[2]<=nums[0]){
            return "none";
        }
        unordered_map<int,int> map;
        for(int i:nums){
            map[i]++;
        }
        if(map.size()==3){
            return "scalene";
        }
        if(map.size()==2){
            return "isosceles";
        }
        return "equilateral";
    }
};