class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int> map;
        for(auto row:grid){
            for(auto i:row){
                map[i]++;
            }
        }
        vector<int> result;
        for(auto &[key,value]:map){
            if(value==2){
                result.push_back(key);
            }
        }
        for(int i=1;i<=n*n;i++){
            if(map.find(i)==map.end()){
                result.push_back(i);
            }
        }
        return result;
    }
};