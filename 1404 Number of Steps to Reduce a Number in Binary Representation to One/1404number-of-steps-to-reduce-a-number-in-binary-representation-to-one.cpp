class Solution {
public:
    void plusone(string &s){
        int i=s.size()-1;
        bool carry=false;
        if(s[i]=='0'){s[i]='1';}
        else{
            s[i]='0';
            carry=true;
        }
        i--;
        while(i>=0 && carry){
            if(s[i]=='0'){
                s[i]='1';carry=false;
            }
            else{s[i]='0';}
            i--;
        }
        if(carry){s='1'+s;}
    }

    int numSteps(string s) {
        int result=0;
        while(s!="1"){
            if(s.back()=='0'){s.pop_back();}
            else{
                plusone(s);
            }
            result++;
        }
        return result;
    }
};