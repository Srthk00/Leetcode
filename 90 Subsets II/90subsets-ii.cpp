class Solution {
public:
    void generate(vector<int> &nums,int i,vector<vector<int>> &result,vector<int> &subset){
        if(i==nums.size()){
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        generate(nums,i+1,result,subset);
        subset.pop_back();
        i++;
        while(i<nums.size() && nums[i]==nums[i-1])  i++;
        generate(nums,i,result,subset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        generate(nums,0,result,subset);
        return result;
    }
};