class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int i=0;
        unordered_set<string> st;
        while(i+k<=s.size()){
            st.insert(s.substr(i,k));
            i++;
        }
        return st.size()==(int)pow(2,k);
    }
};