class Solution {
public:
    string minWindow(string s, string t) {
        vector<long long> tmap(128,0);
        for(char ch:t){
            tmap[ch]++;
        }
        int start=0;
        long long i=0,j=0,ressize=1e9,need=t.size();
        while(j<s.size()){
            if(tmap[s[j]]-->0){need--;}
            j++;
            while(need==0){
                if((j-i)<ressize){
                    ressize=(j-i);
                    start=i;
                }
                if((++tmap[s[i]])>0){need++;}
                i++;
            }
        }
        return ressize==1e9?"":s.substr(start,ressize);
    }
};