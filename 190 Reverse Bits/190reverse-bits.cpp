class Solution {
public:
    string to_binary(int n){
        if(n==0){return "0";}
        string result="";
        while(n>0){
            result+=to_string(n%2);
            n/=2;
        }
        int k=32-result.size();
        result.append(k,'0');
        reverse(result.begin(),result.end());
        return result;
    }

    int to_decimal(string str){
        int result=0;
        int p=0;
        int i=str.size()-1;
        while(i>=0){
            if(str[i]=='1'){
                result+=(1<<p);
            }
            i--;p++;
        }
        return result;
    }

    int reverseBits(int n) {
        string bits=to_binary(n);
        reverse(bits.begin(),bits.end());
        return to_decimal(bits);
    }
};