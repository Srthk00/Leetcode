class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int state=0;
        int i=0,flag[3]={0,0,0};
        while(i<nums.size()-1){
            if(nums[i]>=nums[i+1]){break;}
            flag[0]=1;
            i++;
        }
        while(i<nums.size()-1){
            if(nums[i]<=nums[i+1]){break;}
            flag[1]=1;
            i++;
        }
        while(i<nums.size()-1){
            if(nums[i]>=nums[i+1]){break;}
            flag[2]=1;
            i++;
        }
        return (flag[0] && flag[1] && flag[2] && i==nums.size()-1)?true:false;
    }
};