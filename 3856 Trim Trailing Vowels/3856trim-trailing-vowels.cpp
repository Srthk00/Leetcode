class Solution {
public:
    bool vo(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){return true;}
        return false;
    }
    
    string trimTrailingVowels(string s) {
        int i;
        for(i=s.size()-1;i>=0;i--){
            if(!vo(s[i])){
                break;
            }
        }
        return s.substr(0,i+1);
    }
};