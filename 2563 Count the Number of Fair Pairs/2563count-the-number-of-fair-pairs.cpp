class Solution {
public:
    long long l(vector<int> &nums,int low,int high,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }

    long long u(vector<int> &nums,int low,int high,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long count=0;
        for(int i=0;i<nums.size();i++){
            long long low=l(nums,i+1,nums.size()-1,lower-nums[i]);
            long long high=u(nums,i+1,nums.size()-1,upper-nums[i]);
            count+=(high-low);
        }
        return count;
    }
};