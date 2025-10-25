class Solution {
public:
    string lexSmallest(string s) {
        string result=s;
        for(int i=1;i<=s.size();i++){
            string first=s;
            reverse(first.begin(),first.begin()+i);
            result=min(result,first);
            string last=s;
            reverse(last.end()-i,last.end());
            result=min(result,last);
        }
        return result;
    }
};