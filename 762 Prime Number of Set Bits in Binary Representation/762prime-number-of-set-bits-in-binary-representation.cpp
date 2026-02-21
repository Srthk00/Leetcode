class Solution {
public:
    bool isprime(int n){
        if(n==1){return false;}
        for(int i=2;i<n;i++){
            if(!(n%i)){return false;}
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int result=0;
        for(int i=left;i<=right;i++){
            int c=__builtin_popcount(i);
            if(isprime(c)){result++;}
        }
        return result;
    }
};