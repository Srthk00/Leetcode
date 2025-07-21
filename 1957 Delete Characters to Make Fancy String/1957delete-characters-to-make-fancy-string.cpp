class Solution {
public:
    string makeFancyString(string s) {
        string result="";
        int n=s.size();
        if(n<=2){
            return s;
        }
        for(int i=1;i<n;i++){
            result+=s[i-1];
            if(s[i-1]==s[i]){
                result+=s[i];
                while(i<n && s[i]==s[i-1]){i++;}
            }
        }
        if(s[n-1]!=s[n-2]){result+=s[n-1];}
        return result;
    }
};