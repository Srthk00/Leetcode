class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        int sum=0;
        for(int i=n-1;i>=0;i--){
            prefix[i]=abs(prefix[i]-sum);
            sum+=nums[i];
        }
        return prefix;
    }
};