class Solution {
public:
    string removeStars(string s) {
        string result="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                result+=s[i];
            }
            else{
                result.erase(result.size()-1);
            }
        }
        return result;
    }
};