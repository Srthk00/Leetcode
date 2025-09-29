class Solution {
public:
    vector<vector<int>> dp;
    int func(vector<int> &nums,int i,int j){
        if(j-i+1<3){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int result=INT_MAX;
        for(int k=i+1;k<j;k++){
            int wt=nums[i]*nums[j]*nums[k]+func(nums,i,k)+func(nums,k,j);
            result=min(result,wt);
        }
        return dp[i][j]=result;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        dp=vector(n,vector<int>(n,-1));
        return func(values,0,n-1);
    }
};