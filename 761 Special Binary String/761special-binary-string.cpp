class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> special;
        int idx=0,sum=0;
        for(int i=0;i<s.size();i++){
            sum+=s[i]=='1'?1:-1;
            if(sum==0){
                string inner=s.substr(idx+1,i-idx-1);
                special.push_back('1'+makeLargestSpecial(inner)+'0');
                idx=i+1;
            }
        }
        sort(special.rbegin(),special.rend());
        string result="";
        for(string &str:special){
            result+=str;
        }
        return result;
    }
};