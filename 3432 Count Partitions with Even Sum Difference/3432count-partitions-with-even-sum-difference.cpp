class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        int result=0;
        for(int i=0;i<n-1;i++){
            if((prefix[n-1]-(2*prefix[i]))%2==0){result++;}
        }
        return result;
    }
};