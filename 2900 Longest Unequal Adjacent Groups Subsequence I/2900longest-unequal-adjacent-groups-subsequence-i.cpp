class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        if(words.size()==0 || words.size()==1){
            return words;
        }
        vector<string> result;
        result.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            if(groups[i]!=groups[i-1]){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};