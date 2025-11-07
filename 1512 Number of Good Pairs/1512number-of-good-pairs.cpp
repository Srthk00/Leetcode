class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int i:nums){freq[i]++;}
        int result=0;
        for(int i:freq){
            result+=(i*(i-1)/2);
        }
        return result;
    }
};