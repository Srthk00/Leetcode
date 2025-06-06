class Solution {
public:
    char min(vector<int> &freq){
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                return i+'a';
            }
        }
        return 'z';
    }

    string robotWithString(string s) {
        string p="";
        stack<char> t;
        vector<int> freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        for(int i=0;i<s.size();i++){
            t.push(s[i]);
            freq[s[i]-'a']--;
            while(!t.empty() && t.top()<=min(freq)){
                p+=t.top();
                t.pop();
            }
        }
        return p;
    }
};