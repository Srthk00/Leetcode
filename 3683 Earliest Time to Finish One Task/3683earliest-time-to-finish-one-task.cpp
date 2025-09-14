class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int result=INT_MAX;
        for(auto &it:tasks){
            result=min(result,it[0]+it[1]);
        }
        return result;
    }
};