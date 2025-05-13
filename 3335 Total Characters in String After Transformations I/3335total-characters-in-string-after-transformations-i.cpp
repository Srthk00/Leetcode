class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> map(26,0);
        for(char ch:s){
            map[ch-'a']++;
        }
        while(t>0){
            vector<int> map2(26,0);
            int i=0;
            while(i<26){
                if(i==25){
                    map2[0]=(map2[0]+map[i])%1000000007;
                    map2[1]=(map2[1]+map[i])%1000000007;
                }
                else{
                    map2[i+1]=(map2[i+1]+map[i])%1000000007;
                }
                i++;
            }
            map=map2;
            t--;
        }
        int count=0;
        for(auto &it:map){
            count=(count+it)%1000000007;
        }
        return count;
    }
};