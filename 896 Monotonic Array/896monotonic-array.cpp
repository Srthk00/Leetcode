class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        // -1 dec, 1-inc
        int state=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]-nums[i+1]==0 || (nums[i]-nums[i+1]>0 && state==-1) || (nums[i]-nums[i+1]<0 && state==1)){continue;}
            else if(state==0){
                if(nums[i]-nums[i+1]>0){state=-1;}
                else if(nums[i]-nums[i+1]<0){state=1;}
            }
            else{return false;}
        }
        return true;
    }
};