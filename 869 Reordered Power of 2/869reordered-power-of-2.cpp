class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<string> st;
        for(int i=0;i<31;i++){
            int num=pow(2,i);
            string str=to_string(num);
            sort(str.begin(),str.end());
            st.insert(str);
        }
        string temp=to_string(n);
        sort(temp.begin(),temp.end());
        return st.find(temp)!=st.end();
    }
};