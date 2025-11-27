class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set st(nums.begin(),nums.end());
        nums.assign(st.begin(),st.end());
        sort(nums.rbegin(),nums.rend());
        int n=nums.size();
        return nums.size()<3?nums[0]:nums[2];
    }
};