class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int count=0;
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            int a=2;
            while(nums[i]!=1){
                if(nums[i]%a==0)
                    set.insert(a);
                while(nums[i]%a==0){
                    nums[i]/=a;
                }
                a++;
            }
        }
        return set.size();
    }
};