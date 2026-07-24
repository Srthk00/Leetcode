class Solution {
public:
    string solve1(int i,string &s){
        int x=i,y=i;
        while(x>=0 && y<s.size()){
            if(s[x]==s[y]){
                x--;y++;
            }
            else{
                break;
            }
        }
        return s.substr(x+1,y-x-1);
    }

    string solve2(int i,int j,string &s){
        int x=i,y=j;
        while(x>=0 && y<s.size()){
            if(s[x]==s[y]){
                x--;y++;
            }
            else{
                break;
            }
        }
        return s.substr(x+1,y-x-1);
    }

    string longestPalindrome(string s) {
        string result="";
        for(int i=0;i<s.size();i++){
            string one=solve1(i,s);
            if(one.size()>result.size()){
                result=one;
            }
            string two=solve2(i,i+1,s);
            if(two.size()>result.size()){
                result=two;
            }
        }
        return result;
    }
};