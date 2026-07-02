class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        int even=0,odd=0;
        int i=nums.size()-1;
        while(i>=0){
            int par=nums[i]%2;
            nums[i]%2==1?odd++:even++;
            nums[i]=nums[i]%2==1?even:odd;
            i--;
        }
        return nums;
    }
};