class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());\
        return st.size()==1?0:1;
    }
};