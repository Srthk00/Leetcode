class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans=1,clast=1,c=1;
        int i=1;
        while(i<n){
            if(nums[i-1]<nums[i]){
                c++;
            }
            else{
                ans=max(ans,c/2);
                ans=max(ans,min(c,clast));
                clast=c;
                c=1;
            }
            i++;
        }
        ans=max(ans,c/2);
        ans=max(ans,min(c,clast));
        return ans;
    }
};