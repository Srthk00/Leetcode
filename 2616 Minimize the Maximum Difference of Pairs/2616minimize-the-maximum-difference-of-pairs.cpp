class Solution {
public:
    int helper(vector<int> &nums,int temp){
        int i=0,count=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=temp){
                count++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=nums[n-1]-nums[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(helper(nums,mid)>=p){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};