class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int> map;
        for(char ch:moves){
            map[ch]++;
        }
        return !(map['U']-map['D']) && !(map['L']-map['R']);
    }
};