class Solution {
public:
    vector<string> result;
    
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

    void generate(int o,int c,string p){
        if(o==0 && c==0){
            if(isValid(p)){
                result.push_back(p);
            }
            return;
        }
        if(o){
            p.push_back('(');
            generate(o-1,c,p);
            p.pop_back();
        }
        if(c){
            p.push_back(')');
            generate(o,c-1,p);
            p.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        generate(n,n,"");
        return result;
    }
};