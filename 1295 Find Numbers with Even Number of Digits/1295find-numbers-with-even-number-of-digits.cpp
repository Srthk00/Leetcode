class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i:nums){
            string str=to_string(i);
            int s=str.size();
            if(s%2==0){
                count++;
            }
        }
        return count;
    }
};