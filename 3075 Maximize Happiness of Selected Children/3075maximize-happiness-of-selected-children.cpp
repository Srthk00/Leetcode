class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long result=0;
        sort(happiness.rbegin(),happiness.rend());
        int took=0,i=0;
        while(k-->0){
            result+=max(0,happiness[i++]-took++);
        }
        return result;
    }
};