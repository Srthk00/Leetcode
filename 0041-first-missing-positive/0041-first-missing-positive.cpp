class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool one=false;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                one=true;
            }
            if(nums[i]<1 || nums[i]>n){
                nums[i]=1;
            }
        }   
        if(!one){
            return 1;
        }
        for(int i=0;i<n;i++){
            int ele=abs(nums[i]);
            int idx=ele-1;
            if(nums[idx]<0){
                continue;
            }
            else{
                nums[idx]=-abs(nums[idx]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};