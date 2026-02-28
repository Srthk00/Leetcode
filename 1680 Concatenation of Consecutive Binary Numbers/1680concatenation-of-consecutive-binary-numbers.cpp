class Solution {
public:
    #define MOD 1000000007

    int concatenatedBinary(int n) {
        long long result=0;
        for(int i=1;i<=n;i++){
            int temp=i;
            int s=0;
            while(temp>0){
                s++;
                temp>>=1;
            }
            result=(result<<s)%MOD;
            result=(result+i)%MOD;
        }
        return (int)result;
    }
};