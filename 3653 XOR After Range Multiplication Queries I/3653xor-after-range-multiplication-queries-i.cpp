class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto &it:queries){
            int l=it[0];
            int r=it[1];
            int k=it[2];
            int v=it[3];
            while(l<=r){
                nums[l]=((long long)nums[l]*v)%1000000007;
                l+=k;
            }
        }
        int result=0;
        for(int i:nums){
            result^=i;
        }
        return result;
    }
};