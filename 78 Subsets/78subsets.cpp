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
        generate(nums,i+1,result,subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        generate(nums,0,result,subset);
        return result;
    }
};