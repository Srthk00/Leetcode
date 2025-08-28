class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        for(int i:nums){
            if(i%2==0){sum+=i;}
        }
        vector<int> result;
        for(auto &it:queries){
            int v=it[0];
            int idx=it[1];
            if(nums[idx]%2==0){
                sum-=nums[idx];
            }
            nums[idx]+=v;
            if(nums[idx]%2==0){
                sum+=nums[idx];
            }
            result.push_back(sum);
        }
        return result;
    }
};