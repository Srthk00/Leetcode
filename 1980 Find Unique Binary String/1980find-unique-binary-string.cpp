class Solution {
public:
    int n;
    unordered_set<string> st;
    string result;

    void func(string str){
        if(str.size()==n){
            if(st.find(str)==st.end()){
                result=str;
            }
            return;
        }
        func(str+"0");
        func(str+"1");
    }

    string findDifferentBinaryString(vector<string>& nums) {
        n=nums.size();
        for(string str:nums){
            st.insert(str);
        }
        func("");
        return result;
    }
};