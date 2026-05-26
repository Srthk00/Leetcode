class Solution {
public:
    int numberOfSpecialChars(string word) {
        int result=0;
        vector<int> freq(128,0);
        for(char ch:word){
            freq[ch]++;
        }
        for(int i=65;i<=91;i++){
            if(freq[i] && freq[i+32]){
                result++;
            }
        }
        return result;
    }
};