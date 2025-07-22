class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        for(char ch:s){
            map[ch]++;
        }
        bool flag=true;
        int result=0;
        for(auto &[c,i]:map){
            if(i%2==0){result+=i;}
            else{
                if(flag){
                    result+=i;
                    flag=false;
                }
                else{
                    result+=i-1;
                }
            }
        }
        return result;
    }
};