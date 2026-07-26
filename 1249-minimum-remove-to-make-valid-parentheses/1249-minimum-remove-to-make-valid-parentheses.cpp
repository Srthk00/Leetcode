class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stk;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(' || ch==')'){
                if(ch=='('){
                    stk.push_back(i);
                }
                else{
                    if(stk.empty()){
                        stk.push_back(i);
                    }
                    else if(s[stk.back()]=='('){
                        stk.pop_back();
                    }
                    else{
                        stk.push_back(i);
                    }
                }
            }
        }
        unordered_set<int> st(stk.begin(),stk.end());
        string result="";
        for(int i=0;i<s.size();i++){
            if(st.find(i)==st.end()){
                result+=s[i];
            }
        }
        return result;
    }
};