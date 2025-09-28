class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int> left(n,0); // increasing
        vector<int> right(n,0); // decreasing
        // marking left
        left[0]=1;
        for(int i=1;i<n;i++){
            left[i]=left[i-1] && nums[i]>nums[i-1]?1:0;
        }
        // marking right
        right[n-1]=1;
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1] && nums[i+1]<nums[i]?1:0;
        }
        long long result=1e18;
        for(int i=0;i<n-1;i++){
            if(left[i] && right[i+1]){
                long long l=prefix[i];
                long long r=prefix[n-1]-prefix[i];
                result=min(result,abs(r-l));
            }
        }
        return result==1e18?-1:result;
    }
};