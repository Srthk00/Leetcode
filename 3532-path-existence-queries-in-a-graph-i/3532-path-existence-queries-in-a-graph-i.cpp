class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> temp(n);
        int i=1;
        while(i<n){
            while(i<n && (nums[i]-nums[i-1])<=maxDiff){
                temp[i]=temp[i-1];
                i++;
            }
            if(i<n){
                temp[i]=temp[i-1]+1;
                i++;
            }
        }
        vector<bool> result; 
        for(auto &it:queries){
            result.push_back(temp[it[0]]==temp[it[1]]);
        }
        return result;
    }
};