class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26),visited(26);
        for(char ch:s){
            freq[ch-'a']++;
        }
        string result;
        for(char ch:s){
            if((!visited[ch-'a'])){
                while(!result.empty() && result.back()>ch){
                    if(freq[result.back()-'a']>0){
                        visited[result.back()-'a']=0;
                        result.pop_back();
                    }
                    else{
                        break;
                    }
                }
                visited[ch-'a']=1;
                result.push_back(ch);
            }
            freq[ch-'a']--;
        }
        return result;
    }
};