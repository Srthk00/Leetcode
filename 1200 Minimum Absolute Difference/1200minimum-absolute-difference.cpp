class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mindiff=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            mindiff=min(mindiff,abs(nums[i]-nums[i+1]));
        }
        vector<vector<int>> result;
        for(int i=0;i<nums.size()-1;i++){
            if(abs(nums[i]-nums[i+1])==mindiff){
                result.push_back({nums[i],nums[i+1]});
            }
        }
        return result;
    }
};