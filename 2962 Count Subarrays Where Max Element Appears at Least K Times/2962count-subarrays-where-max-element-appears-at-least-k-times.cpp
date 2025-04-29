class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int m=*max_element(nums.begin(),nums.end());
        int kcount=0;
        long long count=0;
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==m){
                kcount++;
            }
            while(kcount>=k){
                count+=nums.size()-j;
                if(nums[i]==m){
                    kcount--;
                }
                i++;
            }
            j++;
        }
        return count;
    }
};