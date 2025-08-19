class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result=0;
        long long o=0,n=0;
        while(o<nums.size()){
            if(nums[o]==0){
                n++;
            }
            else{
                result+=(n*(n+1))/2;
                n=0;
            }
            o++;
        }
        result+=(n*(n+1))/2;
        return result;
    }
};