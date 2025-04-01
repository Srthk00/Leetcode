class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s1=strs[0];
        string s2=strs[strs.size()-1];
        int i=0,j=0;
        string result="";
        while(i<s1.size() && j<s1.size()){
            if(s1[i]==s2[j]){
                result+=s1[i];
                i++;j++;
            }
            else{
                break;
            }
        }
        return result;
    }
};