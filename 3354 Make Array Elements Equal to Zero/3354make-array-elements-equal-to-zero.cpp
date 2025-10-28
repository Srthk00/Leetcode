class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int result=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                long long left=prefix[i];
                long long right=prefix[n-1]-prefix[i];
                long long diff=abs(left-right);
                if(diff==0){result+=2;}
                else if(diff==1){result++;}
            }
        }
        return result;
    }
};