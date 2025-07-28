class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=k-1;
        int max_sum=accumulate(nums.begin(),nums.begin()+k,0);
        int curr=max_sum;
        while(j<n-1){
            curr-=nums[i];
            i++;j++;
            curr+=nums[j];
            max_sum=max(max_sum,curr);
        }
        return (double)max_sum/k;
    }
};