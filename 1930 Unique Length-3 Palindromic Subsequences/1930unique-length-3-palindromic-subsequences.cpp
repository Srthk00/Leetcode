class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,set<int>> mp;
        unordered_set<char> chars;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            chars.insert(ch);
            mp[ch].insert(i);
        }
        int result=0;
        for(char ch:chars){
            int left=*mp[ch].begin();
            int right=*prev(mp[ch].end());
            unordered_set<char> temp;
            for(int i=left+1;i<right;i++){
                temp.insert(s[i]);
            }
            result+=temp.size();
        }
        return result;
    }
};