class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size(),result=1e9;
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        while(i<n){
            while(j<n && (long long)nums[i]*k>=nums[j]){
                j++;
            }
            result=min(result,i+n-j);
            i++;
        }
        return result;
    }
};