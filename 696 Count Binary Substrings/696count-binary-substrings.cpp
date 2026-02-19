class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr=0,prev=0;
        int result=0;
        int i=0;
        while(i<s.size()){
            prev=curr;
            curr=0;
            while(i<s.size()-1 && s[i]==s[i+1]){
                i++;curr++;
            }
            i++;curr++;
            result+=min(curr,prev);
        }
        return result;
    }
};