class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'
        || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){return true;}
        return false;
    }

    string sortVowels(string s) {
        vector<int> upper,lower,vow;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(isvowel(ch)){
                vow.push_back(i);
                if(ch>='A' && ch<='Z'){
                    upper.push_back(ch);
                }
                else{
                    lower.push_back(ch);
                }
            }
        }
        sort(upper.begin(),upper.end());
        sort(lower.begin(),lower.end());
        int i=0,u=0,l=0;
        while(u<upper.size()){
            s[vow[i++]]=upper[u++];
        }
        while(l<lower.size()){
            s[vow[i++]]=lower[l++];
        }
        return s;
    }
};