class Solution {
public:
    int startswith(char p,string &s){
        int result=0;
        for(char ch:s){
            if(ch!=p){
                result++;
            }
            p=p=='1'?'0':'1';
        }
        return result;
    }

    int minOperations(string s) {
        int zero=startswith('0',s);
        int one=startswith('1',s);
        return min(zero,one);
    }
};