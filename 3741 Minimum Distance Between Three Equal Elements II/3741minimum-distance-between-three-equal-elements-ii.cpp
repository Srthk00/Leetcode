class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        vector<pair<int,int>> result(m+1,{-1,-1});
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            if(result[val].first!=-1 && result[val].second!=-1){
                res=min(res,2*(i-result[val].first));
            }
            result[val].first=result[val].second;
            result[val].second=i;
        }
        return res==INT_MAX?-1:res;
    }
};