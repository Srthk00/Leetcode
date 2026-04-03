class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int e=0,o=1;
        while(e<nums.size() && o<nums.size()){
            if(nums[e]%2==1 && nums[o]%2==0){
                swap(nums[e],nums[o]);
                e+=2;
                o+=2;
            }
            else if(nums[e]%2==0){
                e+=2;
            }
            else if(nums[o]%2==1){
                o+=2;
            }
        }
        return nums;
    }
};