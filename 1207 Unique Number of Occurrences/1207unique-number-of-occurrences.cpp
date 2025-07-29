class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i:arr){
            map[i]++;
        }
        unordered_set<int> s;
        for(auto &[i,f]:map){
            s.insert(f);
        }
        return s.size()==map.size();
    }
};