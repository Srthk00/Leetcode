class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mini=1e9,minj=1e9;
        for(auto &it:ops){
            mini=min(mini,it[0]);
            minj=min(minj,it[1]);
        }
        return mini!=1e9?mini*minj:m*n;
    }
};