class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // all even, all odd, even-odd, odd-even
        int x1=0,x2=0,x3=0,x4=0;
        for(int i:nums){
            if(i%2==0){x1++;}
            else{x2++;}
        }
        int i=0;
        while(i<nums.size()){
            if(nums[i]%2==0){
                x3++;
                while(i<nums.size()){
                    if(nums[i]%2==1){
                        x3++;
                        break;
                    }
                    i++;
                }
            }
            i++;
        }
        i=0;
        while(i<nums.size()){
            if(nums[i]%2==1){
                x4++;
                while(i<nums.size()){
                    if(nums[i]%2==0){
                        x4++;
                        break;
                    }
                    i++;
                }
            }
            i++;
        }
        return max({x1,x2,x3,x4});
    }
};