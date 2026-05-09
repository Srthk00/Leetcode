class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int result=nums[0];
        for(int i:nums){
            if(abs(i)<abs(result)){result=i;}
            else if(abs(result)==abs(i)){result=max(result,i);}
        }
        return result;
    }
};