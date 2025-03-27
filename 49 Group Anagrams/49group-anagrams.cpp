class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(string str:strs){
            vector<int> freq(26,0);
            for(int i=0;i<str.size();i++){
                freq[str[i]-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+=","+to_string(freq[i]);
            }
            map[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto i:map){
            result.push_back(i.second);
        }
        return result;
    }
};