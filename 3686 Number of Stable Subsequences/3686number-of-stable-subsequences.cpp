class Solution {
public:
    vector<vector<vector<int>>>dp;
    int func(vector<int> &nums,int i,int par,int count){
        if(i==nums.size()){return 0;}
        if(dp[i][par][count]!=-1){return dp[i][par][count];}
        long long result=0;
        result+=func(nums,i+1,par,count); // skip
        
        // not skip
        int p=(nums[i]%2)+1;
        if(par==0){ // if no element is picked yet, pick the element
            result+=1;
            result+=func(nums,i+1,p,1);
        }
        else if(par==p){
            // if count==2, cannot pick so skip
            if(count!=2){
                result+=1;
                result+=func(nums,i+1,p,count+1);
            }
        }
        else{ // if parity is not as last one, we can simply pick it
            result+=1;
            result+=func(nums,i+1,p,1);
        }
        return dp[i][par][count]=(result%1000000007);
    }
    
    int countStableSubsequences(vector<int>& nums) {
        dp=vector<vector<vector<int>>> (nums.size(),vector<vector<int>>(3,vector<int>(3,-1)));
        // i,parity,count(cannot be more than 2)
        return func(nums,0,0,0);
    }
};