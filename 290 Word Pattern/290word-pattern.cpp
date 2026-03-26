class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> word;
        int i=0;
        while (i<s.size()) {
            while(i<s.size() && s[i]==' ')
                i++;
            if(i>=s.size())
                break;
            int j=i;
            while(j<s.size() && s[j]!=' ')
                j++;
            string t=s.substr(i,j-i);
            word.push_back(t);
            i=j;
        }
        if(pattern.size()!=word.size()){
            return false;
        }
        unordered_map<char,string> map1;
        unordered_map<string,char> map2;
        for(int i=0;i<pattern.size();i++){
            if(map1.find(pattern[i])!=map1.end() && map1[pattern[i]]!=word[i]){
                return false;
            }
            if(map2.find(word[i])!=map2.end() && map2[word[i]]!=pattern[i]){
                return false;
            }
            map1[pattern[i]]=word[i];
            map2[word[i]]=pattern[i];
        }
        return true;
    }
};