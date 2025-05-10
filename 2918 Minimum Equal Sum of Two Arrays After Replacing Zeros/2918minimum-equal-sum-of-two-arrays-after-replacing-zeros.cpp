class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        int count1=0;
        long long sum2=0;
        int count2=0;
        for(int i:nums1){
            if(i==0){
                count1++;
            }
            sum1+=i;
        }
        for(int i:nums2){
            if(i==0){
                count2++;
            }
            sum2+=i;
        }
        if(count1==0 && count2==0){
            return (sum1==sum2)?sum1:-1;
        }
        else if(count1==0){
            return (sum2+count2<=sum1)?sum1:-1;
        }
        else if(count2==0){
            return (sum1+count1<=sum2)?sum2:-1;
        }
        return max(sum1+count1,sum2+count2);
    }
};