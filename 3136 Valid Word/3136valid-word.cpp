class Solution {
public:
    bool isValid(string word) {
        string valid="aeiou";
        bool v=false,c=false;
        if(word.size()<3){return false;}
        for(char ch:word){
            if(!isalnum(ch)){return false;}
            if(valid.find(tolower(ch))!=string::npos){v=true;}
            if(isalpha(ch) && valid.find(tolower(ch))==string::npos){c=true;}
        }
        if(v && c){return true;}
        return false;
    }
};