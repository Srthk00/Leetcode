class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({i,nums[i]});
        }
        sort(arr.begin(),arr.end(),[](pair<int,int> &a,pair<int,int> &b){
            return a.second>b.second;
        });
        vector<pair<int,int>> maxk(arr.begin(),arr.begin()+k);
        sort(maxk.begin(),maxk.end());
        vector<int> result;
        for(auto &it:maxk){
            result.push_back(it.second);
        }
        return result;
    }
};