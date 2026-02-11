class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        int i=1;
        while(i<s.size()){
            char br=s[i];
            if(br=='(' || br=='[' || br=='{'){st.push(br);i++;}
            else{
                if(st.empty()){return false;}
                if((br==')' && st.top()=='(') || (br==']' && st.top()=='[') || (br=='}' && st.top()=='{')){st.pop();}
                else{return false;}
                i++;
            }
        }
        return st.empty();
    }
};