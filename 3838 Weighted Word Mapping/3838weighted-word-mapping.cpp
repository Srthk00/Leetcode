class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result="";
        for(string w:words){
            int sum=0;
            for(char ch:w){
                sum+=weights[ch-'a'];
            }
            int c=sum%26;
            result+=('z'-c);
        }
        return result;
    }
};