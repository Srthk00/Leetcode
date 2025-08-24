class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result=0,curr=0;
        bool zero=true;
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==1){
                j++;
                curr++;
            }
            else if(zero){
                zero=false;
                j++;
            }
            else{
                result=max(curr,result);
                while(i<nums.size() && nums[i]==1){
                    i++;curr--;
                }
                i++;
                j++;
            }
        }
        result=max(curr,result);
        if(result==nums.size()){return result-1;}
        return result;
    }
};