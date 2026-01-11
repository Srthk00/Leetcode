class Solution {
public:
    vector<int> next,prev;
    stack<int> st;
    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        next.assign(n,n);prev.assign(n,-1);
        while(!st.empty()){st.pop();}
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

    int maximalRectangle(vector<vector<char>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int result=0;
        vector<int> nums(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums[j]=(mat[i][j]=='1')?nums[j]+1:0;
            }
            result=max(result,largestRectangleArea(nums));
        }
        return result;
    }
};