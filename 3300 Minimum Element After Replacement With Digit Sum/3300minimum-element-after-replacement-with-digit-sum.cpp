class Solution {
public:
    int minElement(vector<int>& nums) {
        int result=1e9;
        for(int i:nums){
            int temp=0;
            while(i>0){
                temp+=i%10;
                i/=10;
            }
            result=min(result,temp);
        }
        return result;
    }
};