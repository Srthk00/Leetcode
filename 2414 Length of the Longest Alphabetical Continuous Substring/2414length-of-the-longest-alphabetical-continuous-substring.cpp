class Solution {
public:
    int longestContinuousSubstring(string s) {
        if(s.size()==1){return 1;}
        int i=0;
        int result=0;
        while(i<s.size()-1){
            int currlen=1;
            while(s[i]+1==s[i+1]){
                currlen++;i++;
            }
            i++;
            result=max(result,currlen);
        }
        return result;
    }
};