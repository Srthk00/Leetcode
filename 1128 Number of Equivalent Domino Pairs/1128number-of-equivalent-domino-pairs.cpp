class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(auto &it:dominoes){
            if(it[0]>it[1]){
                swap(it[0],it[1]);
            }
        }
        unordered_map<int,int> map;
        for(auto &it:dominoes){
            map[it[0]*10+it[1]]++;
        }
        int result=0;
        for(auto &it:map){
            int n=it.second;
            result+=(n*(n-1))/2;
        }
        return result;
    }
};