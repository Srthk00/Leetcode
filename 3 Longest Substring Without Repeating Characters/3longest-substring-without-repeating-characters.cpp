class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1)
            return s.size();
        vector<int> freq(256,0);
        int i=0,j=0;
        int result=0;
        while(j<s.size()){
            if(freq[s[j]]==0){
                freq[s[j]]++;
                j++;
            }
            else{
                int curr=j-i;
                result=max(curr,result);
                char x=s[j];
                while(i<j && s[i]!=x){
                    freq[s[i]]--;
                    i++;
                }
                freq[s[i]]--;
                i++;
            }
        }
        result=max(result,j-i);
        return result;
    }
};