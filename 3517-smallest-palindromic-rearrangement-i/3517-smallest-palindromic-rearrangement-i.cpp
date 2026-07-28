class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        char mid;
        s="";
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                if(freq[i]&1){
                    mid=i+'a';
                }
                for(int j=0;j<freq[i]/2;j++){
                    s+=i+'a';
                }
            }
        }
        string copy=s;
        reverse(copy.begin(),copy.end());
        if(n%2){
            s+=mid;
        }
        s+=copy;
        return s;
    }
};