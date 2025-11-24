class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int num=nums[0];
        vector<bool> result;
        result.push_back(num==0?true:false);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==1){
                num=(num*2)+1;
            }
            else{
                num*=2;
            }
            num%=5;
            result.push_back(num%5==0);
        }
        return result;
    }
};