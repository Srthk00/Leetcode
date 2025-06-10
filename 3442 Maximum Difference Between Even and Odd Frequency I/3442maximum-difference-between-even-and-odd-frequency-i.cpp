class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        int a1=0,a2=101;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1){a1=max(a1,freq[i]);}
            else if(freq[i]!=0){a2=min(a2,freq[i]);}
        }
        return a1-a2;
    }
};