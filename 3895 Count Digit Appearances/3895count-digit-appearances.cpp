class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int result=0;
        for(int i:nums){
            string temp=to_string(i);
            for(char ch:temp){
                if(ch==(digit+'0')){
                    result++;
                }
            }
        }
        return result;
    }
};