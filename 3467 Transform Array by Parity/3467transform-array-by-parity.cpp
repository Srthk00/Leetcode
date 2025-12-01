class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int odd=0,even=0;
        for(int i:nums){
            if(i%2==0){even++;}
            else{odd++;}
        }
        int i=0;
        while(even-->0){
            nums[i++]=0;
        }
        while(odd-->0){
            nums[i++]=1;
        }
        return nums;
    }
};