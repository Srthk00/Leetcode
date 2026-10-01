class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for(char ch:s){
            if(st.empty()){
                st.push_back(ch);
            }
            else if(ch=='[' || ch=='{' || ch=='('){
                st.push_back(ch);
            }
            else{
                if((ch==']' && st.back()=='[') || (ch==')' && st.back()=='(') || (ch=='}' && st.back()=='{')){
                    st.pop_back();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};