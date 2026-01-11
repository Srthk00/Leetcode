class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        vector<int> next(n,n),prev(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<nums[st.top()]){
                next[st.top()]=i;st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]<nums[st.top()]){
                prev[st.top()]=i;st.pop();
            }
            st.push(i);
        }
        int result=0;
        for(int i=0;i<n;i++){
            result=max(result,nums[i]*(next[i]-prev[i]-1));
        }
        return result;
    }
};