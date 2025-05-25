class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count=0;
        unordered_map<string,int> map;
        for(auto &i:words){
            string tofind=i;
            reverse(tofind.begin(),tofind.end());
            if(map[tofind]>0){
                count+=4;
                map[tofind]--;
            }
            else{
                map[i]++;
            }
        }
        bool pair=false;
        for(auto &[str,freq]:map){
            if(str[0]==str[1]){
                if(freq%2==1){
                    pair=true;
                }
                count+=(freq/2)*4;
            }
        }
        if(pair){count+=2;}
        return count;
    }
};