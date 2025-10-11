class Solution {
public:
    bool scoreBalance(string s) {
        int i=0;
        while(i<s.size()){
            string str1=s.substr(0,i);
            string str2=s.substr(i);
            int r1=0,r2=0;
            for(char ch:str1){r1+=ch-'a'+1;}
            for(char ch:str2){r2+=ch-'a'+1;}
            if(r1==r2){return true;}
            i++;
        }
        return false;
    }
};