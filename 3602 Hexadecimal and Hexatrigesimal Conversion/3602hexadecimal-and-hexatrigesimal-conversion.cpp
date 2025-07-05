class Solution {
public:
    string base16(int n){
        string str="0123456789ABCDEF";
        string result="";
        while(n>0){
            result+=str[n%16];
            n/=16;
        }
        reverse(result.begin(),result.end());
        return result;
    }

    string base36(int n){
        string str="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string result="";
        while(n>0){
            result+=str[n%36];
            n/=36;
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
    string concatHex36(int n) {
        int n2=n*n;
        int n3=n*n*n;
        return base16(n2)+base36(n3);
    }
};