class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> map;
        for(char c:magazine){
            map[c]++;
        }
        for(char ch:ransomNote){
            if(map.find(ch)==map.end()){
                return false;
            }
            map[ch]--;
            if(map[ch]==0){
                map.erase(ch);
            }
        }
        return true;
    }
};