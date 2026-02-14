class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string &str:words){
            if(str.size()<k){continue;}
            string prefix=str.substr(0,k);
            mp[prefix]++;
        }
        int result=0;
        for(auto &[str,s]:mp){
            if(s>1){result++;}
        }
        return result;
    }
};