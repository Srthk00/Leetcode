class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int result=k;
        while(true){
            if(find(nums.begin(),nums.end(),result)==nums.end()){
                return result;
            }
            result+=k;
        }
        return -1;
    }
};