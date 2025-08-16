class Solution {
public:
    int maximum69Number (int num) {
        string str=to_string(num);
        for(int j=0;j<str.size();j++){
            if(str[j]=='6'){
                str[j]='9';
                break;
            }
        }
        int result=stoi(str);
        return result;
    }
};