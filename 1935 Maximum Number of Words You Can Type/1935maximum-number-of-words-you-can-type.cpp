class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        int result=0;
        string word;
        vector<string> words;
        while(ss>>word){
            words.push_back(word);
        }
        for(string w:words){
            bool flag=true;
            for(char ch:w){
                if(brokenLetters.find(ch)!=string::npos){
                    flag=false;
                    break;
                }
            }
            if(flag){result++;}
        }
        return result;
    }
};