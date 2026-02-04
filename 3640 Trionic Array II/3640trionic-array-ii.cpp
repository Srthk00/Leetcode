class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        long long result=LLONG_MIN;
        for(int i=0;i<n-1;i++){
            int j=i+1;
            while(j<n && nums[j-1]<nums[j]) j++;
            int p=j-1;
            if(p==i) continue;
            long long res=nums[p]+nums[p-1];
            while(j<n && nums[j-1]>nums[j]){
                res+=nums[j];
                j++;
            }
            int q=j-1;
            if(q==p || q==n-1 || nums[q+1]<=nums[q]){
                i=q;
                continue;
            }
            res+=nums[q+1];
            long long sum=0,best=0;
            for(int k=q+2;k<n && nums[k]>nums[k-1];k++){
                sum+=nums[k];
                best=max(best, sum);
            }
            res+=best;
            sum=0;
            best=0;
            for(int k=p-2;k>=i;k--){
                sum+=nums[k];
                best=max(best,sum);
            }
            res+=best;
            result=max(result, res);
            i=q-1;
        }
        return result;
    }
};