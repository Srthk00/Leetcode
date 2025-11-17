class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i=-1,temp=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(temp!=-1){
                    if(i-temp-1<k){return false;}
                }
                temp=i;
            }
        }
        return true;
    }
};