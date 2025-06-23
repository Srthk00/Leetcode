class Solution {
public:
    string greatestLetter(string s) {
        vector<int> upper(26,0);
        vector<int> lower(26,0);
        for(char ch:s){
            if(ch>=97){
                lower[ch-'a']++;
            }
            else{
                upper[ch-'A']++;
            }
        }
        for(int i=25;i>=0;i--){
            if(lower[i] && upper[i]){
                string str(1,i+'A');
                return str;
            }
        }
        return "";
    }
};