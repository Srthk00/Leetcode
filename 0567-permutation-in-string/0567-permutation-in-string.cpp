class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        unordered_map<char,int> mp1,mp2;
        for(char ch:s1){
            mp1[ch]++;
        }
        int n=s1.size();
        int i=0,j=n-1;
        for(int x=i;x<=j;x++){
            mp2[s2[x]]++;
        }
        while(j<s2.size()){
            if(mp1==mp2){
                return true;
            }
            j++;
            mp2[s2[j]]++;
            mp2[s2[i]]--;
            if(mp2[s2[i]]==0){
                mp2.erase(s2[i]);
            }
            i++;
        }
        return false;
    }
};