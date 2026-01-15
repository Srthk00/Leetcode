class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result=0;int curr=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){continue;}
            if(nums[i-1]+1==nums[i]){
                curr++;
            }
            else{
                result=max(result,curr);
                curr=1;
            }
        }
        result=max(result,curr);
        return result;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int length=longestConsecutive(hBars)+1;
        int breath=longestConsecutive(vBars)+1;
        int result=min(length,breath);
        return result*result;
    }
};