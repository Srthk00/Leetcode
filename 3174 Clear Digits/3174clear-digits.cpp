class Solution {
public:
    string clearDigits(string s) {
        string str;
        for(char ch:s){
            if(isdigit(ch)){
                if(!str.empty()){
                    str.pop_back();
                }
            }
            else
                str.push_back(ch);
        }
        return str;
    }
};