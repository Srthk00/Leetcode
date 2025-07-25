class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int sum=0;
        for(int i:st){
            if(i>0){
                sum+=i;
            }
        }
        return sum==0?*max_element(st.begin(),st.end()):sum;
    }
};