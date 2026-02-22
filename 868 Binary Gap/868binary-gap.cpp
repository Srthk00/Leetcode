class Solution {
public:
    int binaryGap(int n) {
        string str=bitset<32>(n).to_string();
        int result=0,prev=-1;
        for(int i=0;i<32;i++){
            if(str[i]=='1'){
                if(prev==-1){prev=i;}
                else{
                    result=max(result,i-prev);
                    prev=i;
                }
            }
        }
        return result;
    }
};