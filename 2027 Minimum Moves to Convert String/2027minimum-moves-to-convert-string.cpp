class Solution {
public:
    int minimumMoves(string s) {
        int count=0;
        int i;
        for(i=0;i<s.size()-2;i++){
            if(s[i]=='X'){
                s[i]='0';
                s[i+1]='0';
                s[i+2]='0';
                count++;
            }
        }
        if(s[i]=='X' || s[i+1]=='X'){count++;}
        return count;
    }
};