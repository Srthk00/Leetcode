class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        vector<long long> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        vector<long long> last(n);
        last[0]=0;
        for(int i=1;i<n;i++){
            last[i]=prefix[i-1];
        }
        int i=0,j=0;
        long long count=0;
        while(j<n){
            long long sum=prefix[j]-last[i];
            if(sum*(j-i+1)<k){
                count+=j-i+1;
                j++;
            }
            else{
                i++;
                if(i>j){
                    j=i;
                }
            }
        }
        return count;
    }
};