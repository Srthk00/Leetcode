class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int result=0,curr=0,ks=0;
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==1){
                j++;curr++;
            }
            else if(ks<k){
                j++;curr++;
                ks++;
            }
            else{
                result=max(result,curr);
                while(i<nums.size() && ks>=k){
                    if(nums[i]==0){ks--;}
                    curr--;
                    i++;
                }
            }
        }
        result=max(result,curr);
        return result;
    }
};