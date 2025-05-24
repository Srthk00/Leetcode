class Solution {
public:
    int digitsum(int n){
        int temp=0;
        while(n>0){
            temp+=n%10;
            n/=10;
        }
        return temp;
    }
    
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i==digitsum(nums[i])){
                return i;
            }
        }
        return -1;
    }
};