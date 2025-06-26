class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){return false;}
        unordered_map<char,char> maps;
        unordered_map<char,char> mapt;
        for(int i=0;i<s.size();i++){
            if(maps.find(s[i])!=maps.end() && maps[s[i]]!=t[i]){return false;}
            if(mapt.find(t[i])!=mapt.end() && mapt[t[i]]!=s[i]){return false;}
            maps[s[i]]=t[i];
            mapt[t[i]]=s[i];
        }
        return true;
    }
};