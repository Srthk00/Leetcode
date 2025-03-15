class Solution {
public:
    long long check(vector<int>& nums,long long mid){
        long long count=0;
        for(int i=0;i<nums.size();i++){
            count+=nums[i]/mid;
        }
        return count;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int low=1,high=*max_element(candies.begin(),candies.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(candies,mid)>=k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};