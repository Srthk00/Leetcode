class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,result=1e9;
        int sum=0;
        while(i<nums.size()){
            if(sum>=target){result=min(result,j-i);sum-=nums[i++];}
            else if(j<nums.size()){sum+=nums[j++];}
            else{break;}
        }
        if(sum==target){result=max(result,j-i);sum-=nums[i++];}
        return result==1e9?0:result;
    }
};