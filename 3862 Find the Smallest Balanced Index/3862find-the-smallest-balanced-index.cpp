class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long limit=1e14;
        int n=nums.size();
        vector<long long> left(n+1,0LL);
        vector<long long> right(n+1,1LL);
        for(int i=0;i<n;i++){
            left[i+1]=left[i]+nums[i];
        }
        for(int i=n-1;i>=0;i--){
            if(right[i+1]>limit/nums[i]){
                right[i]=1e14+1;
            }
            else{
                right[i]=right[i+1]*nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if(left[i]==right[i+1]){return i;}
        }
        return -1;
    }
};