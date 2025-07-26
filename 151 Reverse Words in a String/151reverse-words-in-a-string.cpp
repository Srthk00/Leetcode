class Solution {
public:
    string reverseWords(string s) {
        string result="";
        int i=0,n=s.size();
        while(i<n){
            string temp="";
            while(i<n && s[i]==' '){
                i++;
            }
            while(i<n && s[i]!=' '){
                temp+=s[i++];
            }
            if(!temp.empty()){
                if(!result.empty()){
                    result=temp+" "+result;
                }
                else{
                    result=temp+result;
                }
            }
        }
        return result;
    }
};