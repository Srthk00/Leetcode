class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int dec=n-1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                dec=i-1;
                break;
            }
        }
        if(dec==n-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int minidx=dec+1;
        for(int i=dec+1;i<n;i++){
            if(nums[i]>nums[dec] && nums[i]<=nums[minidx]){
                minidx=i;
            }
        }
        swap(nums[dec],nums[minidx]);
        sort(nums.begin()+dec+1,nums.end());
    }
};