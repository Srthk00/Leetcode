class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,result=1e9,n=nums.size();
        int i=0,j=0;
        while(j<n){
            if(sum>=target){
                result=min(result,j-i);
                sum-=nums[i++];
            }
            else{
                sum+=nums[j++];
            }
        }
        while(sum>=target){
            result=min(result,j-i);
            sum-=nums[i++];
        }
        return result==1e9?0:result;
    }
};