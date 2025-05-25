class Solution {
public:
    bool iscon(char a,char b){
        if((a=='a' && b=='z') || (a=='z' && b=='a')){return true;}
        if(b==a+1 || a==b+1){return true;}
        else{return false;}
    }
    
    string resultingString (string s) {
        stack<int> st;
        int i=0;
        while(i<s.size()){
            if(!st.empty() && iscon(st.top(),s[i])){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string str="";
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};