class Solution {
public:
    string inverse(string str){
        for(int i=0;i<str.size();i++){
            str[i]=str[i]=='1'?'0':'1';
        }
        return str;
    }

    string rev(string str){
        reverse(str.begin(),str.end());
        return str;
    }

    char findKthBit(int n, int k) {
        string result="0",prev="0";
        while(--n>0){
            prev=result;
            string inv=inverse(prev);
            string r=rev(inv);
            result=prev+"1"+r;
        }
        return result[k-1];
    }
};