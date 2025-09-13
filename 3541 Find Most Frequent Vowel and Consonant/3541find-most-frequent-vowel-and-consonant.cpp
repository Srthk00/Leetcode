class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }

    int maxFreqSum(string s) {
        unordered_map<char,int> vow,con;
        for(char ch:s){
            if(isvowel(ch)){vow[ch]++;}
            else{con[ch]++;}
        }
        int v=0,c=0;
        for(auto &it:vow){
            v=max(v,it.second);
        }
        for(auto &it:con){
            c=max(c,it.second);
        }
        return v+c;
    }
};