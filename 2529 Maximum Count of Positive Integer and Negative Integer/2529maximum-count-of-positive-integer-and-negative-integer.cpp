class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]>=0){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        int neg=low;
        low=0;
        high=nums.size()-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]>0){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        int pos=nums.size()-low;
        return max(neg,pos);
    }
};