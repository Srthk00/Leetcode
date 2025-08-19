class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3){return 0;}
        int i=0,j=0;
        int result=0;
        while(i<nums.size()-2){
            int j=i+2;
            int diff=nums[i]-nums[i+1];
            while(j<nums.size() && nums[j-1]-nums[j]==diff){
                result+=(j-i-1);
                j++;
            }
            i=j-1;
        }
        return result;
    }
};