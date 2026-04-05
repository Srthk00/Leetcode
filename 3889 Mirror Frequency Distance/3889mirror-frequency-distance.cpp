class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int> mp;
        for(char &ch:s){
            mp[ch]++;
        }
        int result=0;
        vector<bool> visited(256,false);
        for(char &x:s){
            char m;
            if(x>='0' && x<='9'){
                m='0'+('9'-x);
            }
            else{
                m='a'+('z'-x);
            }
            if(visited[x]){
                continue;
            }
            visited[x]=true;
            visited[m]=true;
            result+=abs(mp[x]-mp[m]);
        }
        return result;
    }
};