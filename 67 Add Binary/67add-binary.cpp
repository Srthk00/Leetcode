class Solution {
public:
    string addBinary(string a, string b) {
        string result="";
        int i=a.size()-1,j=b.size()-1;
        char carry='0';
        while(i>=0 || j>=0){
            char n1=(i>=0?a[i]:'0');
            char n2=(j>=0?b[j]:'0');
            if(n1=='1' && n2=='1'){
                if(carry=='1'){
                    result='1'+result;
                }
                else{
                    result='0'+result;
                    carry='1';
                }
            }
            else if(n1=='0' && n2=='0'){
                if(carry=='1'){
                    result='1'+result;
                    carry='0';
                }
                else{
                    result='0'+result;
                }
            }
            else{
                if(carry=='1'){
                    result='0'+result;
                }
                else{
                    result='1'+result;
                }
            }
            i--;j--;
        }   
        if(carry=='1'){result='1'+result;}
        return result;
    }
};