class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> map;
        for(char ch:s){
            map[ch]++;
        }
        unordered_map<int,vector<char>> group;
        for(auto &[c,f]:map){
            group[f].push_back(c);
        }
        vector<pair<int,vector<char>>> temp;
        for(auto &it:group){
            temp.push_back({it.first,it.second});
        }
        sort(temp.begin(),temp.end(),[](pair<int,vector<char>> &a,pair<int,vector<char>>& b){
            if(a.second.size()==b.second.size()){
                return a.first>b.first;
            }
            return a.second.size()>b.second.size();
        });
        string result="";
        for(char ch:temp[0].second){
            result+=ch;
        }
        return result;
    }
};