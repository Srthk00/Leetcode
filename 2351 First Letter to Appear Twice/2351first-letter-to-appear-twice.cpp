class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> st;
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])!=st.end()){
                return s[i];
            }
            else{
                st.insert(s[i]);
            }
        }
        return 'a';
    }
};