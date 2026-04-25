class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        int flag=nums.size()-1;
        int i=nums.size()-2;
        while(i>=0){
            int val=nums[i];
            if((flag-i)<=val){
                flag=i;
            }
            i--;
        }
        if(flag==0)
            return true;
        return false;
    }
};