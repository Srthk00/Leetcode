class Solution {
public:
    int percentageLetter(string s, char letter) {
        vector<int> freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        return (freq[letter-'a']*100)/s.size();
    }
};