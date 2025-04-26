class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count=0;
        int lastmin=-1,lastmax=-1,start=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                start=i;
            }
            if(nums[i]==minK)
                lastmin=i;
            if(nums[i]==maxK)
                lastmax=i;
            int end=min(lastmin,lastmax);
            int diff=end-start;
            count+=(diff<0)?0:diff;
        }
        return count;
    }
};