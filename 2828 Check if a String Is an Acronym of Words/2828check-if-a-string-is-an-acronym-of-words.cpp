class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if(words.size()!=s.size()){
            return false;
        }
        int i=0;
        for(string str:words){
            if(str[0]==s[i]){
                i++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};