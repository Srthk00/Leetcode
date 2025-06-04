class Solution {
public:
    void permutation(vector<int> nums,vector<vector<int>> &result,int i,int j){
        if(i==j){
            result.push_back(nums);
            return;
        }
        for(int x=i;x<=j;x++){
            swap(nums[x],nums[i]);
            permutation(nums,result,i+1,j);
            swap(nums[x],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutation(nums,result,0,nums.size()-1);
        return result;
    }
};