class Solution {
public:
    vector<vector<int>> dp;
    int func(vector<int> &nums1,vector<int> &nums2,int i,int j){
        if(i==nums1.size() || j==nums2.size()){return -1e9;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int stop=nums1[i]*nums2[j];
        int takeboth=nums1[i]*nums2[j]+func(nums1,nums2,i+1,j+1);
        int takei=func(nums1,nums2,i,j+1);
        int takej=func(nums1,nums2,i+1,j);
        return dp[i][j]=max({takeboth,stop,takei,takej});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        dp.assign(m+1,vector<int>(n+1,-1));
        return func(nums1,nums2,0,0);
    }
};