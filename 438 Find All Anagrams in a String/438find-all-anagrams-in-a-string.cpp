class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()){return {};}
        vector<int> maps(26,0),mapp(26,0);
        for(char ch:p){
            mapp[ch-'a']++;
        }
        vector<int> result;
        for(int i=0;i<p.size();i++){
            maps[s[i]-'a']++;
        }
        int i=p.size()-1;
        int prev=0;
        while(i<s.size()){
            if(maps==mapp){result.push_back(prev);}
            maps[s[prev]-'a']--;
            prev++;i++;
            if(i==s.size()){break;}
            maps[s[i]-'a']++;
        }
        return result;
    }
};